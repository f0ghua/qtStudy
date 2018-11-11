/****************************************************************************
**
** Copyright (C) 2017 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the QtSerialBus module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL3$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPLv3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or later as published by the Free
** Software Foundation and appearing in the file LICENSE.GPL included in
** the packaging of this file. Please review the following information to
** ensure the GNU General Public License version 2.0 requirements will be
** met: http://www.gnu.org/licenses/gpl-2.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef XMODBUSMTCPCLIENT_P_H
#define XMODBUSMTCPCLIENT_P_H

#include "private/qmodbusclient_p.h"
#include "private/qmodbusadu_p.h"
#include "xmodbusmtcpclient.h"

#include <QtCore/qloggingcategory.h>
#include <QtNetwork/qhostaddress.h>
#include <QtNetwork/qtcpsocket.h>
#include <QQueue>
//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API. It exists purely as an
// implementation detail. This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

QT_BEGIN_NAMESPACE

Q_DECLARE_LOGGING_CATEGORY(QT_MODBUS)
Q_DECLARE_LOGGING_CATEGORY(QT_MODBUS_LOW)

class XModbusSerialTcpClientPrivate : public QModbusClientPrivate
{
    Q_DECLARE_PUBLIC(XModbusSerialTcpClient)
    enum State {
        Idle,
        Schedule,
        Send,
        Receive,
    } m_state = Idle;
public:
    void setupTcpSocket()
    {
        Q_Q(XModbusSerialTcpClient);

        m_sendTimer.setSingleShot(true);
        QObject::connect(&m_sendTimer, &QTimer::timeout, q, [this]() { processQueue(); });

        m_responseTimer.setSingleShot(true);
        QObject::connect(&m_responseTimer, &QTimer::timeout, q, [this]() { processQueue(); });

        m_socket = new QTcpSocket(q);

        QObject::connect(m_socket, &QAbstractSocket::connected, [this]() {
            qCDebug(QT_MODBUS) << "(TCP client) Connected to" << m_socket->peerAddress()
                               << "on port" << m_socket->peerPort();
            Q_Q(XModbusSerialTcpClient);
            responseBuffer.clear();
            q->setState(QModbusDevice::ConnectedState);
            //m_state = Idle;
        });

        QObject::connect(m_socket, &QAbstractSocket::disconnected, [this]() {
           qCDebug(QT_MODBUS)  << "(TCP client) Connection closed.";
           Q_Q(XModbusSerialTcpClient);
           q->setState(QModbusDevice::UnconnectedState);
           m_sendTimer.stop();
           m_responseTimer.stop();
           cleanupTransactionStore();
        });

        using TypeId = void (QAbstractSocket::*)(QAbstractSocket::SocketError);
        QObject::connect(m_socket, static_cast<TypeId>(&QAbstractSocket::error),
                         [this](QAbstractSocket::SocketError /*error*/)
        {
            Q_Q(XModbusSerialTcpClient);

            if (m_socket->state() == QAbstractSocket::UnconnectedState) {
                q->setState(QModbusDevice::UnconnectedState);
            }
            q->setError(QModbusClient::tr("TCP socket error (%1).").arg(m_socket->errorString()),
                        QModbusDevice::ConnectionError);
        });

        QObject::connect(m_socket, &QIODevice::readyRead, [this](){
            QByteArray ba = m_socket->read(m_socket->bytesAvailable());
            // strip invalid data from server
            while (!ba.isEmpty() && ba.startsWith(0xFC)) {
                qCDebug(QT_MODBUS_LOW) << "(TCP client) Drop DAM code:" << ba.toHex();
                ba.remove(0, 1);
            }

            responseBuffer += ba;
            qCDebug(QT_MODBUS_LOW) << "(TCP client) Response buffer:" << responseBuffer.toHex();

            // can we read enough for Modbus ADU header?
            if (responseBuffer.size() < mbpaHeaderSize) {
                qCDebug(QT_MODBUS_LOW) << "(TCP client) Modbus ADU not complete";
                return;
            }

            quint8 serverAddress;
            quint16 transactionId, bytesPdu, protocolId;
            QDataStream input(responseBuffer);
            input >> transactionId >> protocolId >> bytesPdu >> serverAddress;

            // stop the timer as soon as we know enough about the transaction
            const bool knownTransaction = m_transactionStore.contains(transactionId);

            qCDebug(QT_MODBUS) << "(TCP client) tid:" << hex << transactionId << "size:"
                << bytesPdu << "server address:" << serverAddress;

            // The length field is the byte count of the following fields, including the Unit
            // Identifier and the PDU, so we remove on byte.
            bytesPdu--;

            int tcpAduSize = mbpaHeaderSize + bytesPdu;
            if (responseBuffer.size() < tcpAduSize) {
                qCDebug(QT_MODBUS) << "(TCP client) PDU too short. Waiting for more data";
                return;
            }

            QModbusResponse responsePdu;
            input >> responsePdu;
            qCDebug(QT_MODBUS) << "(TCP client) Received PDU:" << responsePdu.functionCode()
                               << responsePdu.data().toHex();

            responseBuffer.remove(0, tcpAduSize);

            if (!knownTransaction) {
                qCDebug(QT_MODBUS) << "(TCP client) No pending request for response with "
                    "given transaction ID, ignoring response message.";
                return;
            }

            if (m_state != State::Receive) {
                qCWarning(QT_MODBUS) << "(TCP client) received packet but m_state is " << m_state;
                return;
            }

            m_sendTimer.stop();
            m_responseTimer.stop();
            processQueueElement(responsePdu, m_current);

            m_state = Schedule; // reschedule, even if empty
            m_socket->flush();
            QTimer::singleShot(m_interFrameDelayMilliseconds, [this]() { processQueue(); });
        });

        QObject::connect(m_socket, &QIODevice::bytesWritten, q, [this](qint64 bytes) {
            m_current.bytesWritten += bytes;

            if ((m_state == Send) && (!m_current.reply.isNull()) &&
                    (m_current.bytesWritten >= m_current.adu.size())) {
                qCDebug(QT_MODBUS) << "(TCP client) Send successful:" << m_current.requestPdu;
                m_isWriteFinished = true;
                m_state = Receive;
                m_sendTimer.stop();
                m_responseTimer.start(m_responseTimeoutDuration);
            }
        });
    }

    void scheduleNextRequest()
    {
        m_state = Schedule;
        m_socket->flush();
        //qDebug() << QObject::tr("m_state = %1, this = %2").arg(m_state).arg((int)this);
        QTimer::singleShot(m_interFrameDelayMilliseconds, [this]() { processQueue(); });
    }

    QModbusReply *enqueueRequest(const QModbusRequest &request, int serverAddress,
                                 const QModbusDataUnit &unit,
                                 QModbusReply::ReplyType type) override
    {
        Q_Q(XModbusSerialTcpClient);

        auto reply = new QModbusReply(type, serverAddress, q);
        QueueElement element(reply, request, unit, m_numberOfRetries + 1);
        const quint16 tId = transactionId();
        QByteArray buffer;
        QDataStream output(&buffer, QIODevice::WriteOnly);
        output << tId << quint16(0) << quint16(request.size() + 1) << quint8(serverAddress) << request;
        element.adu = buffer; //.toUpper();
        m_queue.enqueue(element);
        m_transactionStore.insert(tId, element);
        q->connect(reply, &QObject::destroyed, q, [this, tId](QObject *) {
            if (!m_transactionStore.contains(tId))
                return;
            const QueueElement element = m_transactionStore.take(tId);
        });

        if (m_state == Idle)
            scheduleNextRequest();

        incrementTransactionId();
        return reply;
    }

    void processQueue()
    {
        Q_ASSERT_X(!m_sendTimer.isActive(), "processQueue", "send timer active");
        Q_ASSERT_X(!m_responseTimer.isActive(), "processQueue", "response timer active");

        auto writeAdu = [this]() {
            m_isWriteFinished = false;
            responseBuffer.clear();
            m_current.bytesWritten = 0;
            m_current.numberOfRetries--;
            m_socket->write(m_current.adu);
            if (!m_isWriteFinished) {
                m_sendTimer.start(m_interFrameDelayMilliseconds);
            }

            qCDebug(QT_MODBUS) << "(TCP client) Sent Serial PDU:" << m_current.requestPdu;
            qCDebug(QT_MODBUS_LOW).noquote() << "(TCP client) Sent Serial ADU: 0x" + m_current.adu
                .toHex() + ", " + m_current.adu.trimmed().toStdString().data();
        };

        switch (m_state) {
        case Schedule:
            m_current = QueueElement();
            if (!m_queue.isEmpty()) {
                m_current = m_queue.dequeue();
                if (m_current.reply) {
                    m_state = Send;
                    QTimer::singleShot(0, [writeAdu]() { writeAdu(); });
                } else {
                    QTimer::singleShot(0, [this]() { processQueue(); });
                }
            } else {
                m_state = Idle;
            }
            break;

        case Send:
            // send timeout will always happen
            if (m_current.reply.isNull()) {
                scheduleNextRequest();
            } else if (m_current.bytesWritten < m_current.adu.size()) {
                qCDebug(QT_MODBUS) << "(TCP client) Send failed:" << m_current.requestPdu;

                if (m_current.numberOfRetries <= 0) {
                    if (m_current.reply) {
                        m_current.reply->setError(QModbusDevice::TimeoutError,
                            QModbusClient::tr("Request timeout."));
                    }
                    m_current = QueueElement();
                    scheduleNextRequest();
                } else {
                    m_socket->flush();
                    QTimer::singleShot(m_interFrameDelayMilliseconds, [writeAdu]() { writeAdu(); });
                }
            } else {
                qCDebug(QT_MODBUS) << "(TCP client) Send successful:" << m_current.requestPdu;
                m_state = Receive;
                m_responseTimer.start(m_responseTimeoutDuration);
            }

            break;

        case Receive:
            // receive timeout will only happen after successful send
            qCDebug(QT_MODBUS) << "(TCP client) Receive timeout:" << m_current.requestPdu;
            if (m_current.reply.isNull()) {
                scheduleNextRequest();
            } else if (m_current.numberOfRetries <= 0) {
                if (m_current.reply) {
                    m_current.reply->setError(QModbusDevice::TimeoutError,
                        QModbusClient::tr("Response timeout."));
                }
                scheduleNextRequest();
            } else {
                m_state = Send;
                m_socket->flush();
                QTimer::singleShot(m_interFrameDelayMilliseconds, [writeAdu]() { writeAdu(); });
            }
            break;

        case Idle:
        default:
            Q_ASSERT_X(false, "processQueue", QByteArray("unexpected state: ").append(m_state));
            break;
        }
    }

    // TODO: Review once we have a transport layer in place.
    bool isOpen() const override
    {
        if (m_socket)
            return m_socket->isOpen();
        return false;
    }

    void cleanupTransactionStore()
    {
        if (m_transactionStore.isEmpty())
            return;

        qCDebug(QT_MODBUS) << "(TCP client) Cleanup of pending requests";

        for (const auto &elem : qAsConst(m_transactionStore)) {
            if (elem.reply.isNull())
                continue;
            elem.reply->setError(QModbusDevice::ReplyAbortedError,
                                 QModbusClient::tr("Reply aborted due to connection closure."));
        }
        m_transactionStore.clear();
    }

    // This doesn't overflow, it rather "wraps around". Expected.
    inline void incrementTransactionId() { m_transactionId++; }
    inline quint16 transactionId() const { return m_transactionId; }

    QTimer m_sendTimer;
    QTimer m_responseTimer;

    QueueElement m_current;
    QByteArray responseBuffer;

    QQueue<QueueElement> m_queue;
    QHash<quint16, QueueElement> m_transactionStore;
    QTcpSocket *m_socket = nullptr;

    int mbpaHeaderSize = 7;
    int m_interFrameDelayMilliseconds = 100;
    bool m_isWriteFinished = false;

private:
    quint16 m_transactionId = 0; // capturing 'this' will not copy the id.
};

QT_END_NAMESPACE

#endif // XMODBUSMTCPCLIENT_P_H

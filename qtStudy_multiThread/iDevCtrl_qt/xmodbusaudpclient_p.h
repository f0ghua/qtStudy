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

#ifndef XMODBUSAUDPCLIENT_P_H
#define XMODBUSAUDPCLIENT_P_H

#include "xmodbusaudpclient.h"
#include "private/qmodbusclient_p.h"
#include "private/qmodbusadu_p.h"

#include <QtCore/qloggingcategory.h>
#include <QtNetwork/qhostaddress.h>
#include <QtNetwork/qudpsocket.h>
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

//
// reference to Ngi通讯协议Modbus Ascii格式说明.doc section 2.1, if we use udp modbusex
// mode, then port should be 7000
//
#define UDPEX_SUPPORT

#ifdef UDPEX_SUPPORT
const QByteArray UDPEXHDR = QByteArrayLiteral("\x03\x00\x00\x00\x00\x00");
#endif
const char MODBUS_ASCII_DELM_BEGIN  = ':';
const char MODBUS_ASCII_DELM_END[]  = "\r\n";

class XModbusAsciiUdpClientPrivate : public QModbusClientPrivate
{
    Q_DECLARE_PUBLIC(XModbusAsciiUdpClient)
    enum State {
        Idle,
        Schedule,
        Send,
        Receive,
    } m_state = Idle;
public:
    void setupUdpSocket()
    {
        Q_Q(XModbusAsciiUdpClient);

        m_sendTimer.setSingleShot(true);
        QObject::connect(&m_sendTimer, &QTimer::timeout, q, [this]() { processQueue(); });

        m_responseTimer.setSingleShot(true);
        QObject::connect(&m_responseTimer, &QTimer::timeout, q, [this]() { processQueue(); });

        m_socket = new QUdpSocket(q);

        QObject::connect(m_socket, &QAbstractSocket::connected, [this]() {
            qCDebug(QT_MODBUS) << "(UDP client) Connected to" << m_socket->peerAddress()
                               << "on port" << m_socket->peerPort();
            Q_Q(XModbusAsciiUdpClient);
            responseBuffer.clear();
            q->setState(QModbusDevice::ConnectedState);
            //m_state = Idle;
        });

        QObject::connect(m_socket, &QAbstractSocket::disconnected, [this]() {
           qCDebug(QT_MODBUS)  << "(UDP client) Connection closed.";
           Q_Q(XModbusAsciiUdpClient);
           q->setState(QModbusDevice::UnconnectedState);
           m_sendTimer.stop();
           m_responseTimer.stop();
        });

        using TypeId = void (QAbstractSocket::*)(QAbstractSocket::SocketError);
        QObject::connect(m_socket, static_cast<TypeId>(&QAbstractSocket::error),
                         [this](QAbstractSocket::SocketError /*error*/)
        {
            Q_Q(XModbusAsciiUdpClient);

            if (m_socket->state() == QAbstractSocket::UnconnectedState) {
                q->setState(QModbusDevice::UnconnectedState);
            }
            q->setError(QModbusClient::tr("UDP socket error (%1).").arg(m_socket->errorString()),
                        QModbusDevice::ConnectionError);
        });

        QObject::connect(m_socket, &QIODevice::readyRead, [this](){
            responseBuffer = m_socket->read(m_socket->bytesAvailable());
            if (responseBuffer.isEmpty())
                return;
#ifdef UDPEX_SUPPORT
            if (responseBuffer.size() < UDPEXHDR.size()) {
                qCDebug(QT_MODBUS) << "(UDP client) Modbus ADU not complete";
                return;
            }
            responseBuffer.remove(0, UDPEXHDR.size());
#endif
            qCDebug(QT_MODBUS_LOW).noquote() << "(UDP client) Read Serial ADU: 0x" +
                                                responseBuffer.toHex() + ", " +
                                                responseBuffer.trimmed().toStdString().data();

            while (!responseBuffer.isEmpty() &&
                   !responseBuffer.startsWith(MODBUS_ASCII_DELM_BEGIN)) {
                responseBuffer.remove(0, 1);
            }

            if (responseBuffer.size() < 5) { // ':'(1B) + address(2B) + count(2B)
                qCDebug(QT_MODBUS) << "(UDP client) Modbus ADU not complete";
                return;
            }

            const QModbusSerialAdu tmpAdu(QModbusSerialAdu::Ascii, responseBuffer);
            qCDebug(QT_MODBUS) << "(UDP client) tmpAdu.pdu" << tmpAdu.pdu();
            //const QByteArray &tmpData = tmpAdu.pdu();
            //const QModbusResponse tmpResponse(QModbusPdu::FunctionCode(tmpAdu.data().at(1)), tmpData);
            int pduSizeWithoutFcode = QModbusResponse::calculateDataSize(tmpAdu.pdu());
            if (pduSizeWithoutFcode < 0) {
                // wait for more data
                qCDebug(QT_MODBUS) << "(UDP client) Cannot calculate PDU size for function code:"
                                   << tmpAdu.pdu().functionCode() << ", delaying pending frame";
                return;
            }

            qCDebug(QT_MODBUS) << "(UDP client) calculated PDU size = " << pduSizeWithoutFcode;
            // (server address byte + function code byte + PDU size + 1 bytes CRC)*2 + delimeters
            int aduSize = (2 + pduSizeWithoutFcode + 1)*2 + 3;
            if (tmpAdu.rawSize() < aduSize) {
                qCDebug(QT_MODBUS) << "(UDP client) Incomplete ADU received, ignoring";
                return;
            }

            if (tmpAdu.pdu().functionCode() == QModbusPdu::WriteSingleRegister) {
                const QModbusResponse response = tmpAdu.pdu();
                if (canMatchRequestAndResponse(response, tmpAdu.serverAddress())) {
                    aduSize = (2+response.dataSize()+1)*2 + 3;
                    if (tmpAdu.rawSize() < aduSize)
                        return; // echo matches, probably checksum missing
                }
            }

            const QModbusSerialAdu adu(QModbusSerialAdu::Ascii, responseBuffer.left(aduSize));
            responseBuffer.remove(0, aduSize);

            qCDebug(QT_MODBUS)<< "(UDP client) Received ADU:" << adu.rawData().toHex();
            if (QT_MODBUS().isDebugEnabled() && !responseBuffer.isEmpty())
                qCDebug(QT_MODBUS_LOW) << "(UDP client) Pending buffer:" << responseBuffer.toHex();

            // check CRC
            if (!adu.matchingChecksum()) {
                qCWarning(QT_MODBUS) << "(UDP client) Discarding response with wrong CRC, received:"
                                     << adu.checksum<quint16>() << ", calculated CRC:"
                                     << QModbusSerialAdu::calculateCRC(adu.data(), adu.size());
                return;
            }

            const QModbusResponse response = adu.pdu();
            if (!canMatchRequestAndResponse(response, adu.serverAddress())) {
                qCWarning(QT_MODBUS) << "(UDP client) Cannot match response with open request, "
                    "ignoring";
                return;
            }

            if (m_state != State::Receive) {
                qCWarning(QT_MODBUS) << "(UDP client) received packet but m_state is " << m_state;
                return;
            }

            m_sendTimer.stop();
            m_responseTimer.stop();
            processQueueElement(response, m_current);

            m_state = Schedule; // reschedule, even if empty
            m_socket->flush();
            QTimer::singleShot(m_interFrameDelayMilliseconds, [this]() { processQueue(); });
        });

        QObject::connect(m_socket, &QIODevice::bytesWritten, q, [this](qint64 bytes) {
            m_current.bytesWritten += bytes;

            if ((m_state == Send) && (!m_current.reply.isNull()) &&
                    (m_current.bytesWritten >= m_current.adu.size())) {
                qCDebug(QT_MODBUS) << "(UDP client) Send successful:" << m_current.requestPdu;
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
        Q_Q(XModbusAsciiUdpClient);

        auto reply = new QModbusReply(type, serverAddress, q);
        QueueElement element(reply, request, unit, m_numberOfRetries + 1);
#ifdef UDPEX_SUPPORT
        element.adu.clear();
        element.adu += UDPEXHDR;
#endif
        if (serverAddress == DEVADDR_DIRECT_FORWARD) {
            element.adu += request.data();
        } else {
            element.adu += QModbusSerialAdu::create(QModbusSerialAdu::Ascii, serverAddress, request).toUpper();
        }

        m_queue.enqueue(element);

        if (m_state == Idle)
            scheduleNextRequest();
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

            qCDebug(QT_MODBUS) << "(UDP client) Sent Serial PDU:" << m_current.requestPdu;
            qCDebug(QT_MODBUS_LOW).noquote() << "(UDP client) Sent Serial ADU: 0x" + m_current.adu
                .toHex() + ", " + m_current.adu.mid(6).trimmed().toStdString().data();
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
                qCDebug(QT_MODBUS) << "(UDP client) Send failed:" << m_current.requestPdu;

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
                qCDebug(QT_MODBUS) << "(UDP client) Send successful:" << m_current.requestPdu;
                m_state = Receive;
                m_responseTimer.start(m_responseTimeoutDuration);
            }

            break;

        case Receive:
            // receive timeout will only happen after successful send
            qCDebug(QT_MODBUS) << "(UDP client) Receive timeout:" << m_current.requestPdu;
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

    bool canMatchRequestAndResponse(const QModbusResponse &response, int sendingServer) const
    {
        if (m_current.reply.isNull())
            return false;   // reply deleted
        if (m_current.reply->serverAddress() != sendingServer)
            return false;   // server mismatch
        if (m_current.requestPdu.functionCode() != response.functionCode())
            return false;   // request for different function code
        return true;
    }

    // TODO: Review once we have a transport layer in place.
    bool isOpen() const override
    {
        if (m_socket)
            return m_socket->isOpen();
        return false;
    }

    QTimer m_sendTimer;
    QTimer m_responseTimer;

    QueueElement m_current;
    QByteArray responseBuffer;

    QQueue<QueueElement> m_queue;
    QUdpSocket *m_socket = nullptr;

    int mbpaHeaderSize = 7;
    int m_interFrameDelayMilliseconds = 2;
    bool m_isWriteFinished = false;
private:

};

QT_END_NAMESPACE

#endif // XMODBUSAUDPCLIENT_P_H

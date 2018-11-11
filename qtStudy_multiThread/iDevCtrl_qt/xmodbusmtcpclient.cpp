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

#include "xmodbusmtcpclient.h"
#include "xmodbusmtcpclient_p.h"

#include <QtCore/qurl.h>

QT_BEGIN_NAMESPACE

Q_DECLARE_LOGGING_CATEGORY(QT_MODBUS)
Q_DECLARE_LOGGING_CATEGORY(QT_MODBUS_LOW)

/*!
    \class XModbusSerialTcpClient
    \inmodule QtSerialBus
    \since 5.8

    \brief The XModbusSerialTcpClient class is the interface class for Modbus TCP client device.

    XModbusSerialTcpClient communicates with the Modbus backend providing users with a convenient API.
*/

/*!
    Constructs a XModbusSerialTcpClient with the specified \a parent.
*/
XModbusSerialTcpClient::XModbusSerialTcpClient(QObject *parent)
    : QModbusClient(*new XModbusSerialTcpClientPrivate, parent)
{
    Q_D(XModbusSerialTcpClient);
    d->setupTcpSocket();
}

/*!
    Destroys the XModbusSerialTcpClient instance.
*/
XModbusSerialTcpClient::~XModbusSerialTcpClient()
{
    close();
}

/*!
    \internal
*/
XModbusSerialTcpClient::XModbusSerialTcpClient(XModbusSerialTcpClientPrivate &dd, QObject *parent)
    : QModbusClient(dd, parent)
{
    Q_D(XModbusSerialTcpClient);
    d->setupTcpSocket();
}

/*!
     \reimp
*/
bool XModbusSerialTcpClient::open()
{
    if (state() == QModbusDevice::ConnectedState)
        return true;

    Q_D(XModbusSerialTcpClient);
    if (d->m_socket->state() != QAbstractSocket::UnconnectedState)
        return false;

    const QUrl url = QUrl::fromUserInput(d->m_networkAddress + QStringLiteral(":")
        + QString::number(d->m_networkPort));

    if (!url.isValid()) {
        setError(tr("Invalid connection settings for TCP communication specified."),
            QModbusDevice::ConnectionError);
        qCWarning(QT_MODBUS) << "(TCP client) Invalid host:" << url.host() << "or port:"
            << url.port();
        return false;
    }

    d->m_socket->connectToHost(url.host(), url.port());

    return true;
}

/*!
     \reimp
*/
void XModbusSerialTcpClient::close()
{
    if (state() == QModbusDevice::UnconnectedState)
        return;

    Q_D(XModbusSerialTcpClient);
    d->m_socket->disconnectFromHost();
}

QT_END_NAMESPACE

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

#include "xmodbusmudpclient.h"
#include "xmodbusmudpclient_p.h"

#include <QtCore/qurl.h>

QT_BEGIN_NAMESPACE

Q_DECLARE_LOGGING_CATEGORY(QT_MODBUS)
Q_DECLARE_LOGGING_CATEGORY(QT_MODBUS_LOW)

/*!
    \class XModbusSerialUdpClient
    \inmodule QtSerialBus
    \since 5.8

    \brief The XModbusSerialUdpClient class is the interface class for Modbus TCP client device.

    XModbusSerialUdpClient communicates with the Modbus backend providing users with a convenient API.
*/

/*!
    Constructs a XModbusSerialUdpClient with the specified \a parent.
*/
XModbusSerialUdpClient::XModbusSerialUdpClient(QObject *parent)
    : QModbusClient(*new XModbusSerialUdpClientPrivate, parent)
{
    Q_D(XModbusSerialUdpClient);
    d->setupUdpSocket();
}

/*!
    Destroys the XModbusSerialUdpClient instance.
*/
XModbusSerialUdpClient::~XModbusSerialUdpClient()
{
    close();
}

/*!
    \internal
*/
XModbusSerialUdpClient::XModbusSerialUdpClient(XModbusSerialUdpClientPrivate &dd, QObject *parent)
    : QModbusClient(dd, parent)
{
    Q_D(XModbusSerialUdpClient);
    d->setupUdpSocket();
}

/*!
     \reimp
*/
bool XModbusSerialUdpClient::open()
{
    if (state() == QModbusDevice::ConnectedState)
        return true;

    Q_D(XModbusSerialUdpClient);
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
void XModbusSerialUdpClient::close()
{
    if (state() == QModbusDevice::UnconnectedState)
        return;

    Q_D(XModbusSerialUdpClient);
    d->m_socket->disconnectFromHost();
}

QT_END_NAMESPACE

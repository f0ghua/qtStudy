#include "private/qmodbusclient_p.h"
#include "private/qmodbus_symbols_p.h"

#include <QtSerialBus/qmodbusclient.h>
#include <bitset>

QT_BEGIN_NAMESPACE

void QModbusClientPrivate::processQueueElement(const QModbusResponse &pdu,
                                               const QueueElement &element)
{
    element.reply->setRawResult(pdu);
    if (pdu.isException()) {
        element.reply->setError(QModbusDevice::ProtocolError,
            QModbusClient::tr("Modbus Exception Response."));
        return;
    }

    if (element.reply->type() == QModbusReply::Raw) {
        element.reply->setFinished(true);
        return;
    }

    QModbusDataUnit unit = element.unit;
    if (!processResponse(pdu, &unit)) {
        element.reply->setError(QModbusDevice::UnknownError,
            QModbusClient::tr("An invalid response has been received."));
        return;
    }

    element.reply->setResult(unit);
    element.reply->setFinished(true);
}

bool QModbusClientPrivate::processResponse(const QModbusResponse &response, QModbusDataUnit *data)
{
    switch (response.functionCode()) {
    case QModbusRequest::ReadCoils:
        return processReadCoilsResponse(response, data);
    case QModbusRequest::ReadDiscreteInputs:
        return processReadDiscreteInputsResponse(response, data);
    case QModbusRequest::ReadHoldingRegisters:
        return processReadHoldingRegistersResponse(response, data);
    case QModbusRequest::ReadInputRegisters:
        return processReadInputRegistersResponse(response, data);
    case QModbusRequest::WriteSingleCoil:
        return processWriteSingleCoilResponse(response, data);
    case QModbusRequest::WriteSingleRegister:
        return processWriteSingleRegisterResponse(response, data);
    case QModbusRequest::ReadExceptionStatus:
    case QModbusRequest::Diagnostics:
    case QModbusRequest::GetCommEventCounter:
    case QModbusRequest::GetCommEventLog:
        return false;   // Return early, it's not a private response.
    case QModbusRequest::WriteMultipleCoils:
        return processWriteMultipleCoilsResponse(response, data);
    case QModbusRequest::WriteMultipleRegisters:
        return processWriteMultipleRegistersResponse(response, data);
    case QModbusRequest::ReportServerId:
    case QModbusRequest::ReadFileRecord:
    case QModbusRequest::WriteFileRecord:
    case QModbusRequest::MaskWriteRegister:
        return false;   // Return early, it's not a private response.
    case QModbusRequest::ReadWriteMultipleRegisters:
        return processReadWriteMultipleRegistersResponse(response, data);
    case QModbusRequest::ReadFifoQueue:
    case QModbusRequest::EncapsulatedInterfaceTransport:
        return false;   // Return early, it's not a private response.
    default:
        break;
    }
    return q_func()->processPrivateResponse(response, data);
}

static bool isValid(const QModbusResponse &response, QModbusResponse::FunctionCode fc)
{
    if (!response.isValid())
        return false;
    if (response.isException())
        return false;
    if (response.functionCode() != fc)
        return false;
    return true;
}

bool QModbusClientPrivate::processReadCoilsResponse(const QModbusResponse &response,
                                                    QModbusDataUnit *data)
{
    if (!isValid(response, QModbusResponse::ReadCoils))
        return false;
    return collateBits(response, QModbusDataUnit::Coils, data);
}

bool QModbusClientPrivate::processReadDiscreteInputsResponse(const QModbusResponse &response,
                                                             QModbusDataUnit *data)
{
    if (!isValid(response, QModbusResponse::ReadDiscreteInputs))
        return false;
    return collateBits(response, QModbusDataUnit::DiscreteInputs, data);
}

bool QModbusClientPrivate::collateBits(const QModbusPdu &response,
                                     QModbusDataUnit::RegisterType type, QModbusDataUnit *data)
{
    if (response.dataSize() < QModbusResponse::minimumDataSize(response))
        return false;

    const QByteArray payload = response.data();
    // byte count needs to match available bytes
    if ((payload.size() - 1) != payload[0])
        return false;

    if (data) {
        uint value = 0;
        for (qint32 i = 1; i < payload.size(); ++i) {
            const std::bitset<8> byte = payload[i];
            for (qint32 currentBit = 0; currentBit < 8 && value < data->valueCount(); ++currentBit)
                data->setValue(value++, byte[currentBit]);
        }
        data->setRegisterType(type);
    }
    return true;
}

bool QModbusClientPrivate::processReadHoldingRegistersResponse(const QModbusResponse &response,
                                                               QModbusDataUnit *data)
{
    if (!isValid(response, QModbusResponse::ReadHoldingRegisters))
        return false;
    return collateBytes(response, QModbusDataUnit::HoldingRegisters, data);
}

bool QModbusClientPrivate::processReadInputRegistersResponse(const QModbusResponse &response,
                                                             QModbusDataUnit *data)
{
    if (!isValid(response, QModbusResponse::ReadInputRegisters))
        return false;
    return collateBytes(response, QModbusDataUnit::InputRegisters, data);
}

bool QModbusClientPrivate::collateBytes(const QModbusPdu &response,
                                      QModbusDataUnit::RegisterType type, QModbusDataUnit *data)
{
    if (response.dataSize() < QModbusResponse::minimumDataSize(response))
        return false;

    // byte count needs to match available bytes
    const quint8 byteCount = quint8(response.data().at(0));
    if ((response.dataSize() - 1) != byteCount)
        return false;

    // byte count needs to be odd to match full registers
    if (byteCount % 2 != 0)
        return false;

    if (data) {
        QDataStream stream(response.data().remove(0, 1));

        QVector<quint16> values;
        const quint8 itemCount = byteCount / 2;
        for (int i = 0; i < itemCount; i++) {
            quint16 tmp;
            stream >> tmp;
            values.append(tmp);
        }
        data->setValues(values);
        data->setRegisterType(type);
    }
    return true;
}

bool QModbusClientPrivate::processWriteSingleCoilResponse(const QModbusResponse &response,
    QModbusDataUnit *data)
{
    if (!isValid(response, QModbusResponse::WriteSingleCoil))
        return false;
    return collateSingleValue(response, QModbusDataUnit::Coils, data);
}

bool QModbusClientPrivate::processWriteSingleRegisterResponse(const QModbusResponse &response,
    QModbusDataUnit *data)
{
    if (!isValid(response, QModbusResponse::WriteSingleRegister))
        return false;
    return collateSingleValue(response, QModbusDataUnit::HoldingRegisters, data);
}

bool QModbusClientPrivate::collateSingleValue(const QModbusPdu &response,
                                       QModbusDataUnit::RegisterType type, QModbusDataUnit *data)
{
    if (response.dataSize() != QModbusResponse::minimumDataSize(response))
        return false;

    quint16 address, value;
    response.decodeData(&address, &value);
    if ((type == QModbusDataUnit::Coils) && (value != Coil::Off) && (value != Coil::On))
        return false;

    if (data) {
        data->setRegisterType(type);
        data->setStartAddress(address);
        data->setValues(QVector<quint16>{ value });
    }
    return true;
}

bool QModbusClientPrivate::processWriteMultipleCoilsResponse(const QModbusResponse &response,
                                                             QModbusDataUnit *data)
{
    if (!isValid(response, QModbusResponse::WriteMultipleCoils))
        return false;
    return collateMultipleValues(response, QModbusDataUnit::Coils, data);
}

bool QModbusClientPrivate::processWriteMultipleRegistersResponse(const QModbusResponse &response,
                                                                 QModbusDataUnit *data)
{
    if (!isValid(response, QModbusResponse::WriteMultipleRegisters))
        return false;
    return collateMultipleValues(response, QModbusDataUnit::HoldingRegisters, data);
}

bool QModbusClientPrivate::collateMultipleValues(const QModbusPdu &response,
                                      QModbusDataUnit::RegisterType type, QModbusDataUnit *data)
{
    if (response.dataSize() != QModbusResponse::minimumDataSize(response))
        return false;

    quint16 address, count;
    response.decodeData(&address, &count);

    // number of registers to write is 1-123 per request
    if ((type == QModbusDataUnit::HoldingRegisters) && (count < 1 || count > 123))
        return false;

    if (data) {
        data->setValueCount(count);
        data->setRegisterType(type);
        data->setStartAddress(address);
    }
    return true;
}

bool QModbusClientPrivate::processReadWriteMultipleRegistersResponse(const QModbusResponse &resp,
                                                                     QModbusDataUnit *data)
{
    if (!isValid(resp, QModbusResponse::ReadWriteMultipleRegisters))
        return false;
    return collateBytes(resp, QModbusDataUnit::HoldingRegisters, data);
}

QModbusReply *QModbusClientPrivate::sendRequest(const QModbusRequest &request, int serverAddress,
                                                const QModbusDataUnit *const unit)
{
    Q_Q(QModbusClient);

    if (!isOpen() || q->state() != QModbusDevice::ConnectedState) {
        //qCWarning(QT_MODBUS) << "(Client) Device is not connected";
        q->setError(QModbusClient::tr("Device not connected."), QModbusDevice::ConnectionError);
        return nullptr;
    }
/*
    if (!request.isValid()) {
        //qCWarning(QT_MODBUS) << "(Client) Refuse to send invalid request.";
        q->setError(QModbusClient::tr("Invalid Modbus request."), QModbusDevice::ProtocolError);
        return nullptr;
    }
*/
    if (unit)
        return enqueueRequest(request, serverAddress, *unit, QModbusReply::Common);
    return enqueueRequest(request, serverAddress, QModbusDataUnit(), QModbusReply::Raw);
}

QT_END_NAMESPACE

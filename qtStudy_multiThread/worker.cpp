#include "busframe.h"
#include "worker.h"
#include "xcommdefine.h"

#include <QFile>
#include <QDataStream>
#include <QDebug>
#include <QThread>

Worker::Worker(TraceModel *model, QObject *parent)
    : QObject(parent)
    , m_model(model)
{

}

void Worker::run()
{

}

bool Worker::loadBinLogFile(const QString &fileName)
{
    QFile file;
    file.setFileName(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        return false;
    }

    QDataStream ds;
    ds.setDevice(&file);

    quint32 timestamp = 0;
    quint8 msgLen = 0;
    quint32 msgId = 0;
    quint8 idFmtTestByte = 0;
    QByteArray data;
    quint8 byte;
    quint8 dataLen = 0;
    quint8 busInfo = 0;
    quint8 bus = 0;

    QVector<BusFrame> frames;

    while(!ds.atEnd()) {
        ds >> timestamp >> msgLen >> busInfo >> idFmtTestByte;
        // TX OR RX
        bool isTx = busInfo & 0x02;
        switch((busInfo & 0X78)) {
        case 0x10: // can1
            bus = BUS_CAN1;
            break;
        case 0x18: // can2
            bus = BUS_CAN2;
            break;
//        case 0x20: // can fd1
//            bus = BUS_CANFD1;
//            break;
//        case 0x28: // can fd2
//            bus = BUS_CANFD2;
//            break;

        case 0x30: // lin 1
            bus = BUS_LIN1;
            break;
//        case 0x38: // lin 2
//            bus = BUS_LIN2;
//            break;
        default:
            qDebug() << "BinLogParser bus not supported yet!";
        }

        if ((idFmtTestByte & 0x80) != 0) {
            //extended can id
            msgId = (idFmtTestByte << 24);
            //get the 3 bytes left, total 4 bytes
            for (quint32 i = 0; i < sizeof(quint32) - 1; i++) {
                ds >> byte;
                msgId |= (byte << (8 * (2 - i)));
            }
            dataLen = msgLen - sizeof(msgId) - 1;  // decrease the one byte busInfo
        } else {
            //normal can id
            quint16 normId = (idFmtTestByte << 8);
            dataLen = msgLen - sizeof(normId) - 1;  // decrease the one byte busInfo
            ds >> byte;
            normId |= byte;
            msgId = normId;
        }

        //msgLen is the length include msgId and data field and the error code
        data.clear();
        for (int i = 0; i < dataLen - 1; i++) {
            ds >> byte;
            data.append(byte);
        }

        quint8 completeCode = 0;
        ds >> completeCode;

        BusFrame frame;
        frame.setId(msgId);
        frame.setData(data);
        frame.setBus(bus);
        frame.setDir(isTx?BusFrame::eDirTx:BusFrame::eDirRx);
        frame.setTime(timestamp);

        frames.append(frame);
        //emit frameCatched(frame);
        //QThread::usleep(10);
    }

    qDebug() << "parser finished with frame count" << frames.count();

    m_model->frameAppendAll(frames);

    return true;
}

void Worker::handle_loadFile(const QString &filePath)
{
    loadBinLogFile(filePath);
}

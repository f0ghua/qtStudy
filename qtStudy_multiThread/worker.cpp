#include "worker.h"
#include "canconnfactory.h"
#include "xbusframe.h"

#include <QCoreApplication>
#include <QTime>
#include <QTimer>

/*
// Create seed for the random
// That is needed only once on application startup
QTime time = QTime::currentTime();
qsrand((uint)time.msec());
*/
static int randInt(int low, int high)
{
    // Random number between low and high
    return qrand() % ((high + 1) - low) + low;
}

#define SET_BIT(data, bit) 			(data) = (data)|(1<<(bit))
#define SET_STD_ID(ba, c, r) {                              \
    quint8 c = 0;                                           \
    quint32 id = r?randInt(1, 0x7FF):0x39A;                 \
    c |= (id >> 8)&0x07;                                    \
    ba.append(c);                                           \
    ba.append(id & 0xFF);                                   \
    }

#define SET_EXT_ID(ba, c, r) {                              \
    quint8 c = 0;                                           \
    quint32 id = r?randInt(0x800, 0x1FFFF800):0x14DA99F1;   \
    SET_BIT(c, 7);                                          \
    c |= (id >> 24)&0x1F;                                   \
    ba.append(c);                                           \
    ba.append((id >> 16) & 0xFF);                           \
    ba.append((id >> 8) & 0xFF);                            \
    ba.append((id) & 0xFF);                                 \
    }

static const char G_FRAMEENDSTR[2] = {(char)0xFF, (char)0x00};
static const char G_FRAMEESCAPECHAR = 0xFF;

static void packFrame(QByteArray &data)
{
    int pos, from = 0;

    // escape 0xFF
    while ((pos = data.indexOf(G_FRAMEESCAPECHAR, from)) != -1) {
        data.insert(pos, G_FRAMEESCAPECHAR);
        from = pos + 2; //jump 2 escape chars
    }

    // append the end
    data.append(QByteArray::fromRawData(G_FRAMEENDSTR, sizeof(G_FRAMEENDSTR)));
}

// STD with fix id, 8 bytes data(0x55), bit count = 112, 500000/112 = 4464
static int buildCanFrameRaw(int idType, bool idRandomId, bool isRandomData, int dataLen, QByteArray &raw)
{
    int i = 0;

    raw.clear();
    raw.append(0x50); // no timestamp, tx frame
    if (idType == 0) { // STD
        SET_STD_ID(raw, c, idRandomId);
    } else if (idType == 1) { // EXT
        SET_EXT_ID(raw, c, idRandomId);
    } else { // Random
        int type = randInt(0, 1);
        if (type) {
            SET_EXT_ID(raw, c, idRandomId);
        } else {
            SET_STD_ID(raw, c, idRandomId);
        }
    }

    for (int j = 0; j < dataLen; j++) {
        quint8 c = isRandomData?randInt(0, 0xFF):0x55;
        raw.append(c);
    }

    packFrame(raw);

    return i;
}

Worker::Worker(QObject *parent) : QObject(parent)
{
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
}

Worker::~Worker()
{

}

void Worker::run()
{
    m_timer = new QTimer(this);
    m_timer->setInterval(1000);
    connect(m_timer, &QTimer::timeout, this, &Worker::handleTimeout);
    m_timer->start();

    while (m_isRunning) {
        switch (m_workingState) {
        case eBENCHMARKING:
        {
            QByteArray raw;
            buildCanFrameRaw(0, false, false, 8, raw);
            XBusFrame frame(raw);

            m_canConnection->sendFrame(frame);

//            for(int i = 0; i < 10000; i++);

//            if (m_canConnection->txCount() >= 40000) {
//                m_workingState = eIDLE;
//            }

            break;
        }
        case eIDLE:
            break;
        }

        if (m_canConnection) {
            XBusFrame *pFrame = NULL;
            while( (pFrame = m_canConnection->getRxQueue().peek() ) ) {
                m_canConnection->getRxQueue().dequeue();
            }
        }

        QCoreApplication::processEvents();
    }
}

void Worker::onWorkStop()
{
    m_isRunning = false;
}

void Worker::createConnection(const QString &devName)
{
    if (!m_canConnection) {
        m_canConnection = CANConnFactory::create(devName);
    } else {
        if (m_canConnection->devName() != devName) {
            delete m_canConnection;
            m_canConnection = CANConnFactory::create(devName);
        }
    }
    m_canConnection->open();
}

void Worker::startBenchmark()
{
    m_workingState = eBENCHMARKING;
}

void Worker::stopBenchmark()
{
    m_workingState = eIDLE;
}

void Worker::handleTimeout()
{
    if (!m_canConnection)
        return;

    static quint64 prevRxCount = 0, prevTxCount = 0;
    QString msg;
    msg = QString("tx = %1(%2/s), rx = %3(%4/s)").\
            arg(m_canConnection->txCount()).arg(m_canConnection->txCount()-prevTxCount).\
            arg(m_canConnection->rxCount()).arg(m_canConnection->rxCount()-prevRxCount);
    qDebug() << msg;
    prevRxCount = m_canConnection->rxCount();
    prevTxCount = m_canConnection->txCount();
}

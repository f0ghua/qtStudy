#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "worker.h"

#include <QThread>
#include <QDebug>
#include <QSettings>

bool m_isHighLowByteOrder = true;
quint32 m_startBit;
quint32 m_bitSize = 11;
static bool setStartBitByPosition(quint16 bitPosition)
{
    if (m_isHighLowByteOrder) {
        quint16 currByteBits = (bitPosition % 8 + 1);
        bool isMultiBytes = (currByteBits < m_bitSize) ? true : false;
        if (!isMultiBytes) {
            m_startBit = bitPosition - m_bitSize + 1;
        } else {
            quint16 netxByteMsbPostion = ((bitPosition+1)/8 + 1)*8 - 1;
            quint16 leftBits = m_bitSize - currByteBits;
            while (leftBits >= 8) {
                netxByteMsbPostion += 8;
                leftBits -= 8;
            }

            m_startBit = netxByteMsbPostion - leftBits + 1;
        }
    } else {
        m_startBit = bitPosition;
    }

    //qDebug() << "m_startBit = " << m_startBit;

    return true;
}

#include <stdbool.h>

typedef int8_t         		sint8;
typedef uint8_t       		uint8;
typedef char				char_t;
typedef int16_t        		sint16;
typedef uint16_t      		uint16;
typedef int32_t         	sint32;
typedef uint32_t       		uint32;
typedef int64_t  			sint64;
typedef uint64_t  			uint64;
typedef uint_least8_t       uint8_least;
typedef uint_least16_t      uint16_least;
typedef uint_least32_t      uint32_least;
typedef int_least8_t        sint8_least;
typedef int_least16_t       sint16_least;
typedef int_least32_t       sint32_least;
typedef float               float32;
typedef double              float64;

#ifndef FALSE
#define FALSE		false
#endif
#ifndef TRUE
#define TRUE		true
#endif

/* For CRC 8*/
#define CRC8_START_VALUE        0xFFU
#define CRC8_XOR                0xFFU

/* @req 4.0.3/E2E0200 */
typedef enum {
    E2E_P01_DATAID_BOTH = 0x0,
    E2E_P01_DATAID_ALT = 0x1,
    E2E_P01_DATAID_LOW = 0x2
} E2E_P01DataIDMode;

typedef struct  {
    uint16 CounterOffset;
    uint16 CRCOffset;
    uint16 DataID;
    E2E_P01DataIDMode DataIDMode;
    uint16 DataLength;
    uint8 MaxDeltaCounterInit;
} E2E_P01ConfigType;

static const uint8 crc8_tab[256] = {
    0x0, 0x1d, 0x3a, 0x27, 0x74, 0x69, 0x4e, 0x53,
    0xe8, 0xf5, 0xd2, 0xcf, 0x9c, 0x81, 0xa6, 0xbb,
    0xcd, 0xd0, 0xf7, 0xea, 0xb9, 0xa4, 0x83, 0x9e,
    0x25, 0x38, 0x1f, 0x2, 0x51, 0x4c, 0x6b, 0x76,
    0x87, 0x9a, 0xbd, 0xa0, 0xf3, 0xee, 0xc9, 0xd4,
    0x6f, 0x72, 0x55, 0x48, 0x1b, 0x6, 0x21, 0x3c,
    0x4a, 0x57, 0x70, 0x6d, 0x3e, 0x23, 0x4, 0x19,
    0xa2, 0xbf, 0x98, 0x85, 0xd6, 0xcb, 0xec, 0xf1,
    0x13, 0xe, 0x29, 0x34, 0x67, 0x7a, 0x5d, 0x40,
    0xfb, 0xe6, 0xc1, 0xdc, 0x8f, 0x92, 0xb5, 0xa8,
    0xde, 0xc3, 0xe4, 0xf9, 0xaa, 0xb7, 0x90, 0x8d,
    0x36, 0x2b, 0xc, 0x11, 0x42, 0x5f, 0x78, 0x65,
    0x94, 0x89, 0xae, 0xb3, 0xe0, 0xfd, 0xda, 0xc7,
    0x7c, 0x61, 0x46, 0x5b, 0x8, 0x15, 0x32, 0x2f,
    0x59, 0x44, 0x63, 0x7e, 0x2d, 0x30, 0x17, 0xa,
    0xb1, 0xac, 0x8b, 0x96, 0xc5, 0xd8, 0xff, 0xe2,
    0x26, 0x3b, 0x1c, 0x1, 0x52, 0x4f, 0x68, 0x75,
    0xce, 0xd3, 0xf4, 0xe9, 0xba, 0xa7, 0x80, 0x9d,
    0xeb, 0xf6, 0xd1, 0xcc, 0x9f, 0x82, 0xa5, 0xb8,
    0x3, 0x1e, 0x39, 0x24, 0x77, 0x6a, 0x4d, 0x50,
    0xa1, 0xbc, 0x9b, 0x86, 0xd5, 0xc8, 0xef, 0xf2,
    0x49, 0x54, 0x73, 0x6e, 0x3d, 0x20, 0x7, 0x1a,
    0x6c, 0x71, 0x56, 0x4b, 0x18, 0x5, 0x22, 0x3f,
    0x84, 0x99, 0xbe, 0xa3, 0xf0, 0xed, 0xca, 0xd7,
    0x35, 0x28, 0xf, 0x12, 0x41, 0x5c, 0x7b, 0x66,
    0xdd, 0xc0, 0xe7, 0xfa, 0xa9, 0xb4, 0x93, 0x8e,
    0xf8, 0xe5, 0xc2, 0xdf, 0x8c, 0x91, 0xb6, 0xab,
    0x10, 0xd, 0x2a, 0x37, 0x64, 0x79, 0x5e, 0x43,
    0xb2, 0xaf, 0x88, 0x95, 0xc6, 0xdb, 0xfc, 0xe1,
    0x5a, 0x47, 0x60, 0x7d, 0x2e, 0x33, 0x14, 0x9,
    0x7f, 0x62, 0x45, 0x58, 0xb, 0x16, 0x31, 0x2c,
    0x97, 0x8a, 0xad, 0xb0, 0xe3, 0xfe, 0xd9, 0xc4
};

uint8 Crc_CalculateCRC8(const uint8* Crc_DataPtr,
                        uint32 Crc_Length,
                        uint8 Crc_StartValue8,
                        bool Crc_IsFirstCall )
{
    uint8 crc = 0;    /* Default return value if NULL pointer */

    if (Crc_DataPtr != NULL) {

        crc = Crc_IsFirstCall ? CRC8_START_VALUE : Crc_StartValue8;

        for (uint32 byte = 0; byte < Crc_Length; byte++) {
            crc = crc8_tab[crc ^ *Crc_DataPtr];
            Crc_DataPtr++;
        }

        crc = crc ^ CRC8_XOR;

    }

    return crc;
}

/* The start value is 0x00 for E2E (0xFF is standard in the CRC lib). The final
 * XOR is 0x00 (0xFF is standard) so we must XOR the crc with 0xFF
 */
static uint8 CalculateCrc(E2E_P01ConfigType* Config, uint8 Counter, uint8* Data)
{
    uint8 crc = 0x00;
    uint8 lowerByteId = (uint8)Config->DataID;
    uint8 upperByteId = (uint8)(Config->DataID>>8);

    /* Calculate CRC on the Data ID */
    if (Config->DataIDMode == E2E_P01_DATAID_BOTH)
    {
        crc = Crc_CalculateCRC8(&lowerByteId, 1, crc, FALSE);
        crc = Crc_CalculateCRC8(&upperByteId, 1, crc ^ CRC8_XOR, FALSE);
    }
    else if (Config->DataIDMode == E2E_P01_DATAID_LOW)
    {
        crc = Crc_CalculateCRC8(&lowerByteId, 1, crc, FALSE);
    }
    else if (Counter % 2 == 0)
    {
        crc = Crc_CalculateCRC8(&lowerByteId, 1, crc, FALSE);
    }
    else
    {
        crc = Crc_CalculateCRC8(&upperByteId, 1, crc, FALSE);
    }


    /* Calculate CRC on the data */
    if (Config->CRCOffset >= 8) {
        crc = Crc_CalculateCRC8 (Data, (Config->CRCOffset / 8), crc ^ CRC8_XOR, FALSE);
    }

    if (Config->CRCOffset / 8 < (Config->DataLength / 8) - 1) {
        crc = Crc_CalculateCRC8 (&Data[Config->CRCOffset/8 + 1],
                                (Config->DataLength / 8 - Config->CRCOffset / 8 - 1),
                                crc ^ CRC8_XOR, FALSE);
    }

    return crc ^ CRC8_XOR;

}

quint8 CRC8(quint8 *u8_data, quint8 u8_len)
{
    quint8 i, j;
    quint8 u8_crc8;
    quint8 u8_poly;

    u8_crc8 = 0xFF;
    u8_poly = 0x1D;

    for (i = 0; i < u8_len; i++)
    {
        u8_crc8 ^= u8_data[i];

        for (j = 0; j < 8; j++)
        {
            if (u8_crc8 & 0x80)
            {
                u8_crc8 = (u8_crc8 << 1) ^ u8_poly;
            }
            else
            {
                u8_crc8 <<= 1;
            }
        }
    }

    u8_crc8 ^= (quint8)0xFF;
    return u8_crc8;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //startWorker();
    //setStartBitByPosition(7);
    //qDebug() << m_startBit;

//    quint8 bytes[] = {0x03, 0x0B, 0x00, 0x00, 0x00};
//    E2E_P01ConfigType config = {
//        27,
//        31,
//        0x74,
//        E2E_P01_DATAID_LOW,
//        5,
//        0
//    };
//    qint8 crc = CalculateCrc(&config, 0, static_cast<quint8 *>(bytes));
//    qDebug() << crc;


    std::vector<int> vec;
    for (int i = 0; i < 10; i++) {
        vec.push_back(i);
    }
    vec.push_back(8);
    vec.erase(std::remove(vec.begin(), vec.end(), 8), vec.end());
    qDebug() << vec;
}

MainWindow::~MainWindow()
{
    //stopWorker();
    delete ui;
}

void MainWindow::startWorker()
{
    m_workThread = new QThread();
    m_worker = new Worker();
    m_worker->moveToThread(m_workThread);
    QObject::connect(m_workThread, &QThread::started, m_worker, &Worker::run);
    QObject::connect(m_workThread, &QThread::finished, m_worker, &Worker::deleteLater);
    QObject::connect(m_workThread, &QThread::finished, m_workThread, &QThread::deleteLater);
    //QObject::connect(this, &MainWindow::workStop, m_worker, &Worker::onWorkStop);

    m_workThread->start(QThread::HighPriority);
    qDebug() << "Worker thread started.";
}

void MainWindow::stopWorker()
{
    //emit workStop();

    if(m_workThread && (!m_workThread->isFinished())) {
        m_workThread->quit();
        if(!m_workThread->wait()) {
            qDebug() << "can't stop thread";
        }
        qDebug() << "Worker thread finished.";
    }
}

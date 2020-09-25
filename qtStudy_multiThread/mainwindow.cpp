#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "worker.h"
#include "std_dllapi.h"

#include <QThread>
#include <QDebug>
#include <QTimer>
#include <QLibrary>
#include <QDir>
#include <QtGlobal>


/*!
 * /brief packsigtoarray
 * /param crcinput
 * /param crcinputindex
 * /param signalval rawValue of signal
 * /param signallen
 */
void packsigtoarray(quint8 crcinput[],
                    int& crcinputindex,
                    quint64 signalval,
                    int signallen)
{
    int bytesize, i;

    if(signallen %8 == 0) {
        bytesize = signallen/8;
    } else {
        bytesize = (signallen/8) + 1;
    }

    //put signal to array
    for(i = 0; i<bytesize; i++) {
        crcinput[crcinputindex] = signalval>>(i*8) & 0xff;
        crcinputindex += 1;
    }
}

quint8 CRC(quint8 data_byte_array[], quint8 initcrc, int cb_DATA_BYTE_SIZE)
{
    int byte_index, bit_index;
    quint8 cb_CRC_POLY, initValue;

    initValue = initcrc^0xff;//# initial;
    cb_CRC_POLY = 0x1d;
    for( byte_index = 0; byte_index < cb_DATA_BYTE_SIZE; byte_index++) {
        initValue ^= data_byte_array[byte_index];
        for (bit_index = 0; bit_index < 8; bit_index++) {
            if ((initValue & 0x80) != 0) {
                initValue = ((initValue << 1) & 0xff);
                initValue = initValue ^ cb_CRC_POLY;
            } else {
                initValue = ((initValue << 1) & 0xff);
            }
        }
    }

    return initValue^0xff;
}

quint8 E2E_clac(quint16 dataid, quint8 data[], int datasize)
{
    quint8 a[2], b[1];
    quint8 crc1, crc2, crc3;
    a[0] = dataid & 0xff;
    a[1] = (dataid >> 8) & 0xff;
    b[0] = a[1];
    crc1 = CRC(a, 0xFF, 1);
    crc2 = CRC(b, crc1, 1);
    crc3 = CRC(data, crc2, datasize);
    return crc3^0xff;
}

void crcTest()
{
    quint16 dataid = 0;
#if 0
    {
        quint8 input[100] = {0};
        int crcinputindex = 0;

        // VehModMngtGlbSafe1Cntr
        packsigtoarray(input, crcinputindex, 0, 4);
        // VehModMngtGlbSafe1FltEgyCnsWdSts
        packsigtoarray(input, crcinputindex, 1, 1);
        // VehModMngtGlbSafe1UsgModSts
        packsigtoarray(input, crcinputindex, 0xD, 4);
        // VehModMngtGlbSafe1_UB
        //packsigtoarray(input, crcinputindex, 1, 1);

        for (quint16 i = 0; i < 255; i++) {
            quint8 crc = E2E_clac(i, input, crcinputindex);
            if (crc == 0x5F) {
                qDebug() << "i =" << i;

                dataid = i;
                break;
            }
        }

        quint8 crc = E2E_clac(dataid, input, crcinputindex);
        qDebug() << QString("crc = 0x%1, %2").arg(crc, 0, 16).arg(crc);
    }

    {
        quint8 input[100] = {0};
        int crcinputindex = 0;

        // VehModMngtGlbSafe1Cntr
        packsigtoarray(input, crcinputindex, 1, 4);
        // VehModMngtGlbSafe1FltEgyCnsWdSts
        packsigtoarray(input, crcinputindex, 1, 1);
        // VehModMngtGlbSafe1UsgModSts
        packsigtoarray(input, crcinputindex, 0xD, 4);
        // VehModMngtGlbSafe1_UB
        //packsigtoarray(input, crcinputindex, 1, 1);

        quint8 crc = E2E_clac(dataid, input, crcinputindex);
        qDebug() << QString("crc = 0x%1, %2").arg(crc, 0, 16).arg(crc);
    }
#endif

#if 0
    {
        quint8 input[100] = {0};
        int crcinputindex = 0;

        // BrkPedlSnsrCntr
        packsigtoarray(input, crcinputindex, 0, 4);
        // BrkPedlSnsrQf
        packsigtoarray(input, crcinputindex, 2, 2);
        // BrkPedlSnsrSt
        packsigtoarray(input, crcinputindex, 2, 2);
        // BrkPedlSnsr_UB
        //packsigtoarray(input, crcinputindex, 1, 1);

        for (quint16 i = 0; i < 255; i++) {
            quint8 crc = E2E_clac(i, input, crcinputindex);
            if (crc == 0x3C) {
                qDebug() << "i =" << i;

                dataid = i;
                break;
            }
        }

        quint8 crc = E2E_clac(dataid, input, crcinputindex);
        qDebug() << QString("crc = 0x%1, %2").arg(crc, 0, 16).arg(crc);
    }

    {
        quint8 input[100] = {0};
        int crcinputindex = 0;

        // BrkPedlSnsrCntr
        packsigtoarray(input, crcinputindex, 2, 4);
        // BrkPedlSnsrQf
        packsigtoarray(input, crcinputindex, 2, 2);
        // BrkPedlSnsrSt
        packsigtoarray(input, crcinputindex, 2, 2);
        quint8 crc = E2E_clac(dataid, input, crcinputindex);
        qDebug() << QString("crc = 0x%1, %2").arg(crc, 0, 16).arg(crc);
    }
#endif

#if 0
    {
        quint8 input[100] = {0};
        int crcinputindex = 0;

        // MobDevRPAAuthRespCntr
        packsigtoarray(input, crcinputindex, 5, 4);
        // MobDevRPAAuthResp_UB
        //packsigtoarray(input, crcinputindex, 1, 1);

        for (quint16 i = 0; i < 255; i++) {
            quint8 crc = E2E_clac(i, input, crcinputindex);
            if (crc == 0x5F) {
                qDebug() << "i =" << i;

                dataid = i;
                break;
            }
        }

        quint8 crc = E2E_clac(dataid, input, crcinputindex);

        qDebug() << QString("crc = 0x%1, %2").arg(crc, 0, 16).arg(crc);
    }
#endif
}

enum VKeyGenResultEx
{
  KGRE_Ok = 0,
  KGRE_BufferToSmall = 1,
  KGRE_SecurityLevelInvalid = 2,
  KGRE_VariantInvalid = 3,
  KGRE_UnspecifiedError = 4
};

typedef VKeyGenResultEx (*calculateKeyT)(
        const unsigned char* ipSeedArray,          /* Array for the seed [in] */
        unsigned int iSeedArraySize,               /* Length of the array for the seed [in] */
        const unsigned int iSecurityLevel,         /* Security level [in] */
        const char* ipVariant,                     /* Name of the active variant [in] */
        unsigned char* iopKeyArray,                /* Array for the key [in, out] */
        unsigned int iMaxKeyArraySize,             /* Maximum length of the array for the key [in] */
        unsigned int& oActualKeyArraySize);         /* Length of the key [out] */
//typedef void (*calculateKey)(char *, const char *);

void dllApiCallTest()
{
    Function<VKeyGenResultEx,
            const unsigned char*,
            unsigned int,
            const unsigned int,
            const char*,
            unsigned char*,
            unsigned int,
            unsigned int&> calculateKeyFunc("SeedKey.dll", "GenerateKeyEx");

    const unsigned char seedData[] = {0xE5, 0x15, 0x96, 0x98, 0x68, 0xBC, 0xCB, 0xBC, 0x75, 0x2B, 0x12, 0x86, 0x26, 0xDF, 0x7B, 0x00, 0xA2, 0x3B, 0x3B, 0xB8, 0xD2, 0x0C, 0xAF, 0x39, 0xCD, 0x75, 0x24, 0x20, 0x8F, 0xB2, 0x81, 0xF4};
    QByteArray baSeed = QByteArray::fromRawData(reinterpret_cast<const char *>(&seedData[0]), sizeof(seedData));
    QByteArray baKey(baSeed.size(), 0);
    unsigned int oActualKeyArraySize = 0;
    VKeyGenResultEx ret = calculateKeyFunc(
                seedData,
                sizeof(seedData)/sizeof(seedData[0]),
                0x00,
                nullptr,
                reinterpret_cast<unsigned char *>(baKey.data()),
                baKey.size(),
                oActualKeyArraySize
                );
    qDebug() << baSeed.toHex(' ').constData();
    qDebug() << static_cast<int>(ret) << baKey.toHex(' ').constData();
}

void dllTest()
{
    QString m_scriptFileName = "SeedKey.dll";
    QLibrary m_lib;
    calculateKeyT m_calculateKeyFunc;
    m_lib.setFileName(m_scriptFileName);
    if (m_lib.isLoaded()) {
        m_lib.unload();
    }
    if (m_lib.load()) {
        m_calculateKeyFunc = (calculateKeyT)m_lib.resolve("GenerateKeyEx");
        if (!m_calculateKeyFunc) {
            return;
        }
    } else {
        return;
    }

    const unsigned char seedData[] = {0xE5, 0x15, 0x96, 0x98, 0x68, 0xBC, 0xCB, 0xBC, 0x75, 0x2B, 0x12, 0x86, 0x26, 0xDF, 0x7B, 0x00, 0xA2, 0x3B, 0x3B, 0xB8, 0xD2, 0x0C, 0xAF, 0x39, 0xCD, 0x75, 0x24, 0x20, 0x8F, 0xB2, 0x81, 0xF4};
    QByteArray baSeed = QByteArray::fromRawData(reinterpret_cast<const char *>(&seedData[0]), sizeof(seedData));
    QByteArray baKey(baSeed.size(), 0);
    unsigned int oActualKeyArraySize = 0;
    VKeyGenResultEx ret = m_calculateKeyFunc(
                reinterpret_cast<const unsigned char *>(baSeed.data()),
                baSeed.size(),
                0x01,
                nullptr,
                reinterpret_cast<unsigned char *>(baKey.data()),
                baKey.size(),
                oActualKeyArraySize
                );
    qDebug() << baSeed.toHex(' ').constData();
    qDebug() << static_cast<int>(ret) << baKey.toHex(' ').constData();

}

class c
{
public:
    c() { qDebug() << "c"; }
    ~c() { qDebug() << "~c"; }
};

class b
{
public:
    b() { qDebug() << "b"; }
    ~b() { qDebug() << "~b"; }
};

class a : public b
{
public:
    a() { qDebug() << "a"; }
    ~a() { qDebug() << "~a"; }
private:
    c C;
};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    startWorker();
//    dllApiCallTest();
//    dllTest();
//    a A;

    qputenv("PATH", QDir::toNativeSeparators("D:/gitSource/studyCode/build-qtcreator-Qt5101_msys2_mingw73_32-Debug/lib/qtcreator;C:/msys64/mingw32/lib;C:/msys64/mingw32/bin;d:/expandDrive/c/Qt/Qt5.14.2/Tools/mingw730_32/bin;C:/msys64/mingw32/bin;d:/expandDrive/c/Qt/Qt5.14.2/Tools/mingw730_32/bin;C:/Windows/system32;C:/Windows;C:/Windows/System32/Wbem;C:/Windows/System32/WindowsPowerShell/v1.0/;C:/Program Files (x86)/NVIDIA Corporation/PhysX/Common;D:/expandDrive/c/Git/cmd;;C:/Program Files (x86)/Windows Kits/10/Windows Performance Toolkit/;C:/Program Files (x86)/Microsoft SQL Server/120/Tools/Binn/;C:/Windows/system32/wbem;C:/Program Files (x86)/IVT Corporation/BlueSoleil/Mobile").toLatin1());

    const QString attempt = "D:/gitSource/studyCode/build-qtcreator-Qt5101_msys2_mingw73_32-Debug/lib/qtcreator/plugins/QmlDesignerd4.dll";
    //const QString attempt = "D:/gitSource/studyCode/build-qtcreator-Qt5101_msys2_mingw73_32-Debug/lib/qtcreator/plugins/Cored4.dll";
    auto pHnd = LoadLibrary((wchar_t*)QDir::toNativeSeparators(attempt).utf16());
    //auto pHnd = LoadLibraryEx((wchar_t*)QDir::toNativeSeparators(attempt).utf16(), NULL, LOAD_WITH_ALTERED_SEARCH_PATH);
    qDebug() << GetLastError();
    qDebug() << "pHnd =" << (quint32)pHnd;
}

MainWindow::~MainWindow()
{
//    stopWorker();
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

void MainWindow::executeTask()
{
    quint16 dataid = 179;
    {
        quint8 input[100] = {0};
        int crcinputindex = 0;

        // VehModMngtGlbSafe1Cntr
        packsigtoarray(input, crcinputindex, 1, 4);
        // VehModMngtGlbSafe1FltEgyCnsWdSts
        packsigtoarray(input, crcinputindex, 1, 1);
        // VehModMngtGlbSafe1UsgModSts
        packsigtoarray(input, crcinputindex, 0xD, 4);
        // VehModMngtGlbSafe1_UB
        //packsigtoarray(input, crcinputindex, 1, 1);

        quint8 crc = E2E_clac(dataid, input, crcinputindex);
        qDebug() << QString("crc = 0x%1, %2").arg(crc, 0, 16).arg(crc);
    }
}

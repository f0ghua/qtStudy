#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "worker.h"
#include "windows.h"
#include "QAppLogging.h"
#include "qxtglobalshortcut.h"

#include <QTimer>
#include <QSettings>
#include <QDebug>

#ifdef THREAD_ENABLE
#include <QThread>
#endif

const QString CLASSNAME_DIALOG = "#32770";
const QString CLASSNAME_LISTVIEW = "SysListView32";
const QString CLASSNAME_RICHEDIT = "RichEdit20A";
const QString CLASSNAME_ROOMLIST = "Afx:400000:3:0:1900012:0";
LPTSTR g_classNameDialog = (LPTSTR)CLASSNAME_DIALOG.utf16();
LPTSTR g_classNameListView = (LPTSTR)CLASSNAME_LISTVIEW.utf16();
LPTSTR g_classNameRichEdit = (LPTSTR)CLASSNAME_RICHEDIT.utf16();
LPTSTR g_classNameRoomList = (LPTSTR)CLASSNAME_ROOMLIST.utf16();

const QString APPNAME_HF = "浩方电竞平台 -";
const QString WINDOWNAME_HF_CANCEL1 = "浩方电竞平台";
const QString WINDOWNAME_HF_CANCEL2 = "进入房间";
LPTSTR g_windowNameHfCancel1 = (LPTSTR)WINDOWNAME_HF_CANCEL1.utf16();
LPTSTR g_windowNameHfCancel2 = (LPTSTR)WINDOWNAME_HF_CANCEL2.utf16();

const QString g_targetAppName = APPNAME_HF;
HWND g_hMain = NULL;
HWND g_hListView = NULL;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_settings = new QSettings("./config.ini", QSettings::IniFormat, this);
    m_settings->setIniCodec("UTF-8");

    m_timerClick = new QTimer(this);
    m_timerClick->setInterval(3000);
    connect(m_timerClick, &QTimer::timeout, this, &MainWindow::handleClickTimeout);

    qApp->installEventFilter(this);
    QxtGlobalShortcut* shortcut = new QxtGlobalShortcut(this);
    connect(shortcut, &QxtGlobalShortcut::activated, this, [&]{
        if (m_timerClick->isActive()) {
            m_timerClick->stop();
        } else {
            if (prepareWork()) {
                m_timerClick->start();
            }
        }
    });
    shortcut->setShortcut(QKeySequence("F1"));



    //startWork();

#ifdef THREAD_ENABLE
    startWorker();
#endif
}

MainWindow::~MainWindow()
{
#ifdef THREAD_ENABLE
    stopWorker();
#endif
    delete ui;
}

#ifdef THREAD_ENABLE
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
#endif



BOOL CALLBACK enumChildProc(HWND hwnd, LPARAM lParam)
{
    TCHAR buffer[MAX_PATH];

    ::GetWindowText(hwnd, buffer, MAX_PATH - 1);
    QString appWName = QString::fromWCharArray(buffer);
    //qDebug() << appWName;

    if (appWName.contains(g_targetAppName)) {
        QLOG_DEBUG() << "target app found, name =" << appWName << "hwnd =" << QString("%1").arg((quint32)hwnd, 8, 16, QChar('0'));;
        g_hMain = hwnd;
        return false;
    }

    return true;
}

static QString lptstr2QString(const LPTSTR str)
{
#ifdef UNICODE
    return QString::fromWCharArray(str);
#else
    return QString::fromLocal8Bit(str);
#endif
}

void searchClass(HWND parentHwnd, LPTSTR className, HWND &retHwnd, int dialogDeepth)
{
    HWND childHwnd = NULL;
    LPTSTR tmpClassName;

    dialogDeepth--;
    if (dialogDeepth < 0)
        return;

    if (dialogDeepth > 0) {
        tmpClassName = g_classNameDialog;
    } else {
        tmpClassName = className;
    }

    while (childHwnd = ::FindWindowEx(parentHwnd, childHwnd, tmpClassName, NULL)) {
        qDebug() << dialogDeepth << QString("%1").arg((quint32)childHwnd, 8, 16, QChar('0'));
        if ((dialogDeepth == 0) && childHwnd) {
            qDebug() << "searchClass found class" << lptstr2QString(className) << ", hwnd =" << QString("%1").arg((quint32)childHwnd, 8, 16, QChar('0'));
            retHwnd = childHwnd;
            break;
        }

        searchClass(childHwnd, className, retHwnd, dialogDeepth);
    }

    return;
}


bool MainWindow::closeWindows()
{
    HWND h;

    h = ::FindWindow(NULL, g_windowNameHfCancel1);
    if (h) {
        qDebug() << QString("close hwnd %1").arg((quint32)h, 8, 16, QChar('0'));
        ::SendMessage(h, WM_CLOSE, 0, 0);
        return true;
    }

    return false;
}

bool MainWindow::prepareWork()
{
    QString className = "#32770";
    LPTSTR classNameDialog = (LPTSTR)className.utf16();
    TCHAR buffer[MAX_PATH];

    g_hMain = NULL;
    ::EnumChildWindows(0, enumChildProc, 0);

    if (!g_hMain) {
        QLOG_DEBUG() << "No app found";
        return false;
    }

    g_hListView = NULL;
    searchClass(g_hMain, g_classNameListView, g_hListView, 4);
    if (!g_hListView) {
        QLOG_DEBUG() << "No listview window found";
        return false;
    }

    GetCursorPos(&m_point); // get absolute coordinate
    ScreenToClient(g_hListView, &m_point);  // change to relative coordinate
    //qDebug() << pos.x << pos.y;

    return true;
}

void MainWindow::startWork()
{
    ::PostMessage(g_hListView, WM_LBUTTONDBLCLK, MK_LBUTTON, ((m_point.y<<16)|m_point.x));
}

static void searchClassWithCaption(HWND parentHwnd, LPTSTR className, HWND &retHwnd, int dialogDeepth)
{
    HWND childHwnd = NULL;
    LPTSTR tmpClassName;
    LRESULT ret;

    dialogDeepth--;
    if (dialogDeepth < 0)
        return;

    if (dialogDeepth > 0) {
        tmpClassName = g_classNameDialog;
    } else {
        tmpClassName = className;
    }

    while (childHwnd = ::FindWindowEx(parentHwnd, childHwnd, tmpClassName, NULL)) {
        qDebug() << dialogDeepth << QString("%1").arg((quint32)childHwnd, 8, 16, QChar('0'));
        if ((dialogDeepth == 0)
                && childHwnd
                && (0 != (ret = ::PostMessage(childHwnd, WM_GETTEXTLENGTH, 0, 0)))) {
            qDebug() << QString("searchClassWithCaption found class %1, hwnd = %2, ret = %3").\
                        arg(lptstr2QString(className)).\
                        arg((quint32)childHwnd, 8, 16, QChar('0')).\
                        arg(ret);
            retHwnd = childHwnd;
            break;
        }

        searchClass(childHwnd, className, retHwnd, dialogDeepth);
    }

    return;
}

void MainWindow::handleClickTimeout()
{
    HWND h;

    h = ::FindWindow(NULL, g_windowNameHfCancel1);
    if (h) {
        qDebug() << QString("close %1 hwnd %2").\
                    arg(WINDOWNAME_HF_CANCEL1).\
                    arg((quint32)h, 8, 16, QChar('0'));
        ::PostMessage(h, WM_CLOSE, 0, 0);
        return;
    }

    h = ::FindWindow(NULL, g_windowNameHfCancel2);
    if (h) {
        qDebug() << QString("close %1 hwnd %2").\
                    arg(WINDOWNAME_HF_CANCEL2).\
                    arg((quint32)h, 8, 16, QChar('0'));
        ::PostMessage(h, WM_CLOSE, 0, 0);
        return;
    }
/*
    HWND hRichEdit = NULL;
    searchClassWithCaption(g_hMain, g_classNameRichEdit, hRichEdit, 4);
    if ((hRichEdit)) {
        m_timerClick->stop();
        return;
    }
*/
    startWork();

}

#include "mainwindow.h"
#include "QAppLogging.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QAppLogging::installHandler();
    QAppLogging::instance()->setOutputDest(QAppLogging::eDestFile|QAppLogging::eDestSystem);
    QAppLogging::instance()->setLogFilePath("log.txt");

    MainWindow w;
    w.show();

    return a.exec();
}

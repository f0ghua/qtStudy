#include "mainwindow.h"
#include "QAppLogging.h"

#include <QApplication>
#include <QDir>
#include <QStandardPaths>
#include <QMessageBox>
#include <QDebug>

int main(int argc, char *argv[])
{
    AppLogMessage::installHandler();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

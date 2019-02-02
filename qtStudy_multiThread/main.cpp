#include "mainwindow.h"
#include "applogmessage.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    AppLogMessage::installHandler();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

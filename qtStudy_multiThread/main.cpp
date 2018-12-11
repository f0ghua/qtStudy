#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    qSetMessagePattern("[%{time h:mm:ss.zzz}]: %{category} %{message}");

    return a.exec();
}

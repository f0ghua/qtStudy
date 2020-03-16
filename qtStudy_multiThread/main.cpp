#include "mainwindow.h"
#include "CalculatorDialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

    CalculatorDialog d;
    d.show();

    return a.exec();
}

#include "mainwindow.h"
#include "qapplogging.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QAppLogging::installHandler();
    QAppLogging::instance()->setFilterRulesByLevel(QAppLogging::InfoLevel);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

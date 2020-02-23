#include "mainwindow.h"
#include "QAppLogging.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QAppLogging *appLogging = QAppLogging::instance();
    //appLogging->setFilterRulesByLevel(QAppLogging::LogLevel::DebugLevel);
    appLogging->setFilterRulesByLevel(QAppLogging::LogLevel::OffLevel);
    QAppLogging::installHandler();

    qSetMessagePattern("[%{time yyyyMMdd h:mm:ss.zzz} %{if-debug}D%{endif}%{if-info}I%{endif}%{if-warning}W%{endif}%{if-critical}C%{endif}%{if-fatal}F%{endif}] - %{message}");

    MainWindow w;
    w.show();

    return a.exec();
}

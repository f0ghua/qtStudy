#include "mainwindow.h"
#include "qapplogging.h"
#ifdef CRASHDUMP_DRMINGW
#include "exchndl.h"
#endif

#include <QApplication>

int main(int argc, char *argv[])
{
#ifdef CRASHDUMP_DRMINGW
    ExcHndlInit();
#endif
    QAppLogging::installHandler();
    QAppLogging::instance()->setFilterRulesByLevel(QAppLogging::TraceLevel);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

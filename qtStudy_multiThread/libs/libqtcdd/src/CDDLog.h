#pragma once

//#include "QAppLogging.h"

#include <QDebug>

#define QLOG_TRACE()    qDebug()
#define QLOG_DEBUG()    qInfo()
#define QLOG_INFO()     qInfo()
#define QLOG_WARNING()  qWarning()


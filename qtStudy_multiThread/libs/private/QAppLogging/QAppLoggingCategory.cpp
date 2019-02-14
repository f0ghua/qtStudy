#include "QAppLoggingCategory.h"

#include <QSettings>

// Add Global logging categories (not class specific) here using QAPP_LOGGING_CATEGORY
QAPP_LOGGING_CATEGORY(AppCore,            "appCoreLog")
QAPP_LOGGING_CATEGORY(AppCoreTrace,       "appCoreTraceLog")

const char *QAppLoggingCategoryRegister::_filterRulesSettingsGroup = "LoggingFilters";

QAppLoggingCategoryRegister *QAppLoggingCategoryRegister::instance(void)
{
    static QAppLoggingCategoryRegister inst;
    return &inst;
}

QStringList QAppLoggingCategoryRegister::registeredCategories(void)
{
    QStringList sl;
    foreach (auto options, _registeredCategories) {
        sl.append(options.name);
    }
    return sl;
}

void QAppLoggingCategoryRegister::setCategoryLoggingOn(const QString &category, bool enable)
{
    QList<QAppCategoryOptions>::iterator it;
    QList<QAppCategoryOptions>::iterator end = _registeredCategories.end();
    for (it = _registeredCategories.begin(); it != end; it++) {
        if (it->name == category) {
            it->isEnable = enable;
            break;
        }
    }

    return;
}

bool QAppLoggingCategoryRegister::categoryLoggingOn(const QString &category)
{
    bool enable = false;
    foreach (auto options, _registeredCategories) {
        if (options.name == category) {
            enable = options.isEnable;
            break;
        }
    }

    return enable;
}

void QAppLoggingCategoryRegister::setFilterRulesByLevel(QiLogging::Level severityLevel)
{
    QString filterRules;

    filterRules += "*Log.debug=false\n";
    filterRules += "*Log.info=false\n";
    filterRules += "*Log.warning=false\n";
    filterRules += "*Log.critical=false\n";
    filterRules += "*Log.fatal=false\n";

    foreach (auto options, _registeredCategories) {
        QString &category = options.name;
        bool isCategoryEnable = options.isEnable;
        if (!isCategoryEnable) {
            continue;
        }

        if (severityLevel <= QiLogging::TraceLevel) {
            filterRules += category;
            filterRules += ".debug=true\n";
        }
        if (severityLevel <= QiLogging::DebugLevel) {
            if (!category.contains("TraceLog")) {
                filterRules += category;
                filterRules += ".debug=true\n";
            }
        }
        if (severityLevel <= QiLogging::InfoLevel) {
            filterRules += category;
            filterRules += ".info=true\n";
        }
        if (severityLevel <= QiLogging::WarnLevel) {
            filterRules += category;
            filterRules += ".warning=true\n";
        }
        if (severityLevel <= QiLogging::ErrorLevel) {
            filterRules += category;
            filterRules += ".critical=true\n";
        }
        if (severityLevel <= QiLogging::FatalLevel) {
            filterRules += category;
            filterRules += ".fatal=true\n";
        }
    }

    qDebug() << "Filter rules" << filterRules;
    QLoggingCategory::setFilterRules(filterRules);
}

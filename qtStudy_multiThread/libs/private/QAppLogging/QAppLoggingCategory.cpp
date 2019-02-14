#include "QAppLoggingCategory.h"

#include <QSettings>

// Add Global logging categories (not class specific) here using QAPP_LOGGING_CATEGORY
QAPP_LOGGING_CATEGORY(AppCore,            "appCoreDLog")
QAPP_LOGGING_CATEGORY(AppCore_lowlevel,   "appCoreTLog")

const char *QAppLoggingCategoryRegister::_filterRulesSettingsGroup = "LoggingFilters";

QAppLoggingCategoryRegister *QAppLoggingCategoryRegister::instance(void)
{
    static QAppLoggingCategoryRegister inst;
    return &inst;
}

QStringList QAppLoggingCategoryRegister::registeredCategories(void)
{
    _registeredCategories.sort();
    return _registeredCategories;
}

void QAppLoggingCategoryRegister::setCategoryLoggingOn(const QString& category, bool enable)
{
    QSettings settings;

    settings.beginGroup(_filterRulesSettingsGroup);
    settings.setValue(category, enable);
}

bool QAppLoggingCategoryRegister::categoryLoggingOn(const QString& category)
{
    QSettings settings;

    settings.beginGroup(_filterRulesSettingsGroup);
    return settings.value(category, false).toBool();
}

void QAppLoggingCategoryRegister::setFilterRulesFromSettings(const QString& commandLineLoggingOptions)
{
    if (!commandLineLoggingOptions.isEmpty()) {
        _commandLineLoggingOptions = commandLineLoggingOptions;
    }
    QString filterRules;

    filterRules += "*TLog.debug=false\n";
    filterRules += "*DLog.trace=true\n";

    // Set up filters defined in settings
    foreach (QString category, _registeredCategories) {
        if (categoryLoggingOn(category)) {
            filterRules += category;
            filterRules += ".debug=true\n";
        }
    }

    qDebug() << "Filter rules" << filterRules;
    QLoggingCategory::setFilterRules(filterRules);
}

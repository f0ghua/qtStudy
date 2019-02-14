#ifndef QAPP_LOGGING_CATEGORY_H
#define QAPP_LOGGING_CATEGORY_H

#include <QLoggingCategory>
#include <QStringList>

// Add Global logging categories (not class specific) here using Q_DECLARE_LOGGING_CATEGORY
Q_DECLARE_LOGGING_CATEGORY(AppCore)
Q_DECLARE_LOGGING_CATEGORY(AppCore_lowlevel)

/// @def QAPP_LOGGING_CATEGORY
/// This is a QAPP specific replacement for Q_LOGGING_CATEGORY. It will register the category name into a
/// global list. It's usage is the same as Q_LOGGING_CATEOGRY.
#define QAPP_LOGGING_CATEGORY(name, ...) \
    static QAppLoggingCategory qAppCategory ## name (__VA_ARGS__); \
    Q_LOGGING_CATEGORY(name, __VA_ARGS__)

#define QLOG_DEBUG() qCDebug(AppCore)
#define QLOG_TRACE() qCDebug(AppCore_lowlevel)

class QAppLoggingCategoryRegister : public QObject
{
    Q_OBJECT

public:
    static QAppLoggingCategoryRegister* instance(void);

    /// Registers the specified logging category to the system.
    void registerCategory(const char* category) { _registeredCategories << category; }

    /// Returns the list of available logging category names.
    Q_INVOKABLE QStringList registeredCategories(void);

    /// Turns on/off logging for the specified category. State is saved in app settings.
    Q_INVOKABLE void setCategoryLoggingOn(const QString& category, bool enable);

    /// Returns true if logging is turned on for the specified category.
    Q_INVOKABLE bool categoryLoggingOn(const QString& category);

    /// Sets the logging filters rules from saved settings.
    ///     @param commandLineLogggingOptions Logging options which were specified on the command line
    void setFilterRulesFromSettings(const QString& commandLineLoggingOptions);

private:
    QAppLoggingCategoryRegister(void) { }
    
    QStringList _registeredCategories;
    QString     _commandLineLoggingOptions;

    static const char* _filterRulesSettingsGroup;
};
        
class QAppLoggingCategory
{
public:
    QAppLoggingCategory(const char* category) { QAppLoggingCategoryRegister::instance()->registerCategory(category); }
};

#endif

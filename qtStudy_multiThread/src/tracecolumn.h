#ifndef TRACECOLUMN_H
#define TRACECOLUMN_H

#include <QString>
#include <QVariant>

class BusFrame;

class TraceColumn
{
public:
    enum {
        IDTYPE_SINGLE       = 0,    // single id '<id>'
        IDTYPE_FLEXRAY,             // flexray id string '<id>[<baseCycle>, <repetition>]'
    };

    enum {
        COL_INDEX            = 0,
        COL_TIME,
        COL_CHANNEL,
        COL_ID,
        COL_NAME,
        COL_FORMAT,
        COL_DIRECTION,
        COL_DLC,
        COL_DATA,
        COL_INFO,
        COL_CYCLECOUNT,
        COL_NUMBER
    };

    TraceColumn();
    TraceColumn(int id, const QString &title = QString());
    int id() const {return m_id;}
    void setId(int id);
    QString title() const {return m_title;}
    void setTitle(QString &title);
    QVariant value(const BusFrame &f) const;

    static QString getTrColumnTitle(int id);
    static QVariant getTrColumnValueString(int id, const BusFrame &f);

private:
    int m_id;
    QString m_title;
};

#endif // TRACECOLUMN_H

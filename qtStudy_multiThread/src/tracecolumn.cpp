#include "busframe.h"
#include "tracecolumn.h"
#include "xcommdefine.h"

#include <QString>
#include <QStringList>
#include <QMap>

struct TraceColumnInfo
{
    TraceColumnInfo(int id_, QString title_, QString description_)
        : id(id_), title(title_), description(description_)
    {}

    int id;
    QString title;
    QString description;
};

static const TraceColumnInfo g_defaultTrColValue = {
    0, QString(), QString()
};

static const QMap<int, TraceColumnInfo> g_trColInfos = QMap<int, TraceColumnInfo>{
    {TraceColumn::COL_INDEX,        {TraceColumn::COL_INDEX,        "#",            "Index"}},
    {TraceColumn::COL_TIME,         {TraceColumn::COL_TIME,         "Time",         "Absolute/Relative time"}},
    {TraceColumn::COL_CHANNEL,      {TraceColumn::COL_CHANNEL,      "Channel",      "Channel"} },
    {TraceColumn::COL_ID,           {TraceColumn::COL_ID,           "ID",           "Identify"} },
    {TraceColumn::COL_NAME,         {TraceColumn::COL_NAME,         "Name",         ""} },
    {TraceColumn::COL_FORMAT,       {TraceColumn::COL_FORMAT,       "Type",         ""} },
    {TraceColumn::COL_DIRECTION,    {TraceColumn::COL_DIRECTION,    "Dir",          ""} },
    {TraceColumn::COL_DLC,          {TraceColumn::COL_DLC,          "DLen",         ""} },
    {TraceColumn::COL_DATA,         {TraceColumn::COL_DATA,         "Data",         ""} },
    {TraceColumn::COL_INFO,         {TraceColumn::COL_INFO,         "Info",         ""} },
    {TraceColumn::COL_CYCLECOUNT,   {TraceColumn::COL_CYCLECOUNT,   "Cycle",        ""} },

};

QString TraceColumn::getTrColumnTitle(int id)
{
    return g_trColInfos.value(id, g_defaultTrColValue).title;
}

QVariant TraceColumn::getTrColumnValueString(int id, const BusFrame &f)
{
    switch (id) {
        case COL_TIME:
            return f.time();
        case COL_CHANNEL:
            return (f.bus() < BUS_NUMBER)? (XCD_CONSTANTS::infNames[f.bus()]) : "Err";
        case COL_ID:
            return QString("0x%1").arg(f.id(), 0, 16);
//        case COL_NAME:
//            return f->name;
//        case COL_FORMAT:
//            return f->format;
        case COL_DIRECTION:
            return (f.dir() == BusFrame::eDirRx)?"rx":"tx";
//        case COL_DLC:
//            return f->dataLen;
        case COL_DATA:
            return f.data().toHex(' ').toUpper().constData();
//        case COL_INFO:
//            return f->error;
//        case COL_CYCLECOUNT:
//            return QString::number(f->m_bfPtr->frCycleCount());
        default:
            break;
    }

    return QVariant();
}

TraceColumn::TraceColumn()
{

}

TraceColumn::TraceColumn(int id, const QString &title)
    : m_id(id)
    , m_title(title)
{
    if (m_title.isEmpty()) {
        m_title = getTrColumnTitle(id);
    }
}

void TraceColumn::setId(int id)
{
    m_id = id;
}

void TraceColumn::setTitle(QString &title)
{
    m_title = title;
}

QVariant TraceColumn::value(const BusFrame &f) const
{
    return getTrColumnValueString(m_id, f);
}



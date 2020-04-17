#include "QAppLogging.h"
#include "tracemodel.h"
#include "xcommdefine.h"

#include <QDebug>

TraceModel::TraceModel(QObject *parent) :
    QAbstractTableModel(parent)
{
    m_columnList.clear();
    m_columnList.append(TraceColumn(TraceColumn::COL_INDEX));
    m_columnList.append(TraceColumn(TraceColumn::COL_TIME));
//    m_columnList.append(TraceColumn(TraceColumn::COL_NAME));
    m_columnList.append(TraceColumn(TraceColumn::COL_CHANNEL));
    m_columnList.append(TraceColumn(TraceColumn::COL_DIRECTION));
    m_columnList.append(TraceColumn(TraceColumn::COL_ID));
//    m_columnList.append(TraceColumn(TraceColumn::COL_FORMAT));
//    m_columnList.append(TraceColumn(TraceColumn::COL_DLC));
    m_columnList.append(TraceColumn(TraceColumn::COL_DATA));
//    m_columnList.append(TraceColumn(TraceColumn::COL_INFO));

    connect(&m_updateTimer, &QTimer::timeout, this, &TraceModel::updateView);
    m_updateTimer.setInterval(5000);
    //m_updateTimer.start();

    m_items.reserve(10000);
}

TraceModel::~TraceModel()
{

}

void TraceModel::updateView()
{
    //qDebug() << tr("m_items.size = %1").arg(m_items.size());
    if (m_items.size()) {
//        emit dataChanged(index(0, 0), index(columnCount()-1, m_items.size()-1));
//        emit layoutChanged();

        beginResetModel();
        endResetModel();
    }
}

void TraceModel::clearData()
{
    beginResetModel();
    m_items.clear();
    endResetModel();
}

void TraceModel::frameCatched(const BusFrame &frame)
{
    if (!m_isPause) {
//        qDebug() << "model rx frame" << frame;
        beginInsertRows(QModelIndex(), m_items.size(), m_items.size());
        m_items.append(frame);
        endInsertRows();
    }
}

void TraceModel::frameAppendAll(const QVector<BusFrame> &frames)
{
    qDebug() << frames.at(0);
    m_items.append(frames);
    updateView();
}

QVariant TraceModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    int row = index.row();
    int col = index.column();
    if (row >= m_items.size())
        return QVariant();

    /*
    if (role == Qt::ToolTipRole) {
        return Utils::Base::formatHexNumber(m_items[row].pduPtr()->at(0) & PROTOCOL_ID_MASK);
    }
    */

    if (role != Qt::DisplayRole)
        return QVariant();

    if (m_columnList[col].id() == TraceColumn::COL_INDEX) {
        return row;
    }

    return m_columnList[col].value(m_items[row]);
}

QVariant TraceModel::headerData(int section,
                                   Qt::Orientation orientation,
                                   int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole) {
        return m_columnList[section].title();
    }

    return QVariant();
}

int TraceModel::rowCount(const QModelIndex & /*parent*/) const
{
    return m_items.size();
}

int TraceModel::columnCount(const QModelIndex & /*parent*/) const
{
    return m_columnList.count();
}

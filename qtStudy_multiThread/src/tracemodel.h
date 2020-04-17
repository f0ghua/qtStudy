#ifndef DEVTRACEMODEL_H
#define DEVTRACEMODEL_H

#include "busframe.h"
#include "tracecolumn.h"

#include <QObject>
#include <QAbstractItemModel>
#include <QTimer>

class TraceModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit TraceModel(QObject *parent = 0);
    ~TraceModel();

    QVariant data(const QModelIndex &index, int role) const Q_DECL_OVERRIDE;
    QVariant headerData(int section, Qt::Orientation orientation,
            int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    void clearData();
    bool isPause() const {return m_isPause;}
    void setPauseState(bool state) {m_isPause = state;}
    const BusFrame &getItem(int index) const
    {
        const BusFrame &i = m_items[index];
        return i;
    }
    const QList<TraceColumn> &columns() const {return m_columnList;}

    void frameAppendAll(const QVector<BusFrame> &frames);

public slots:
    void frameCatched(const BusFrame &frame);

private slots:
    void updateView();

private:
    QList<TraceColumn> m_columnList;
    QTimer m_updateTimer;
    QVector<BusFrame> m_items;
    bool m_isPause = false;
};

#endif // DEVTRACEMODEL_H

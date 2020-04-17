#ifndef BUSFRAME_H
#define BUSFRAME_H

#include <QObject>
#include <QDebug>

class BusFrame {
public:
    enum Direction {
        eDirRx,
        eDirTx
    };

    BusFrame();
    void setBus(quint8 bus) {m_bus = bus;}
    quint8 bus() const {return m_bus;}
    void setDir(quint8 dir) {m_dir = dir;}
    quint8 dir() const {return m_dir;}
    void setId(quint32 id) {m_id = id;}
    quint32 id() const {return m_id;}
    void setTime(quint64 ts) {m_msTime = ts;}
    quint64 time() const {return m_msTime;}
    void setData(const QByteArray &d) {m_data = d;}
    const QByteArray &data() const {return m_data;}

private:
    quint8 m_bus;
    quint8 m_dir;
    quint32 m_id;
    quint64 m_msTime;
    QByteArray m_data;
};

QDebug inline operator<<(QDebug d, const BusFrame &o)
{
    QDebugStateSaver saver(d);
    d.nospace().noquote() << "BusFrame: ("
      << "id:" << QString("0x%1").arg(o.id(), 0, 16) << ","
      << "data:" << o.data().toHex().constData() << ","
      << ")";

    return d;
}

#endif // BUSFRAME_H

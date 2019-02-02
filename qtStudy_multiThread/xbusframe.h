#ifndef XBUSFRAME_H
#define XBUSFRAME_H

#include <QObject>

class XBusFramePrivate;

class XBusFrame
{
    Q_DECLARE_PRIVATE(XBusFrame)
public:
    explicit XBusFrame();
    XBusFrame(const QByteArray &raw);
    ~XBusFrame();
    QByteArray &rawData() const;
    XBusFrame &operator=(const XBusFrame &other);

signals:

public slots:

private:

    XBusFramePrivate * const d_ptr;
};

#endif // XBUSFRAME_H

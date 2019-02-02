#include "xbusframe.h"

class XBusFramePrivate
{
    Q_DECLARE_PUBLIC(XBusFrame)
public:
    XBusFramePrivate(XBusFrame *q);
    ~XBusFramePrivate();

    XBusFrame * const q_ptr;
    QByteArray m_rawData;
};

XBusFramePrivate::XBusFramePrivate(XBusFrame *q)
    : q_ptr(q)
{

}

XBusFramePrivate::~XBusFramePrivate()
{

}

XBusFrame::XBusFrame()
    : d_ptr(new XBusFramePrivate(this))
{

}

XBusFrame::XBusFrame(const QByteArray &raw)
    : d_ptr(new XBusFramePrivate(this))
{
    d_ptr->m_rawData = raw;
}

XBusFrame::~XBusFrame()
{
    delete d_ptr;
}

XBusFrame &XBusFrame::operator=(const XBusFrame &other)
{
    d_ptr->m_rawData = other.rawData();
    return *this;
}

QByteArray &XBusFrame::rawData() const
{
    return d_ptr->m_rawData;
}

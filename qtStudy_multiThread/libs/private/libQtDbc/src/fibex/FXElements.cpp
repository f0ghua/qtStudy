#include "FXElements.h"
#include "LogDb.h"
#include "FXFibex.h"

#include <QDomElement>
#include <QDebug>

namespace ASAM {
namespace FIBEX {

FXElements::FXElements(FXFibex *fibex, QObject *parent)
    : QObject(parent)
    , m_fibex(fibex)
    , m_clusterList()
    , m_channelList()
    , m_gatewayList()
    , m_ecus()
    , m_pdus()
    , m_frames()
    , m_functionList()
    , m_signals()
    , m_compositeList()
{
}

FXElements::~FXElements()
{
    qDebug() << "FXElements destructed";
}

bool FXElements::load(const QDomElement &element)
{
    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
#ifndef F_NO_DEBUG
        QLOG_TRACE() << "FXElements::load" << childElement.tagName();
#endif
        if (childElement.tagName() == "fx:SIGNALS") {
            QDomNode framesChild = child.firstChild();
            while (!framesChild.isNull()) {
#ifndef F_NO_DEBUG
                QLOG_TRACE() << "FXElements::load SIGNALS" << childElement.tagName();
#endif
                if (framesChild.toElement().tagName() == "fx:SIGNAL") {
                    FXSignalType *sig = new FXSignalType(m_fibex, this);
                    sig->load(framesChild.toElement());
                    if (!sig->m_id.isEmpty()) {
                        m_signals[sig->m_id] = sig;
                    }
                }
                framesChild = framesChild.nextSibling();
            }
        } else if (childElement.tagName() == "fx:PDUS") {
            QDomNode framesChild = child.firstChild();
            while (!framesChild.isNull()) {
#ifndef F_NO_DEBUG
                QLOG_TRACE() << "FXElements::load PDUS" << childElement.tagName();
#endif
                if (framesChild.toElement().tagName() == "fx:PDU") {
                    FXPduTypeCt *pdu = new FXPduTypeCt(m_fibex, this);
                    pdu->load(framesChild.toElement());
                    if (!pdu->m_id.isEmpty()) {
                        m_pdus[pdu->m_id] = pdu;
                    }
                }
                framesChild = framesChild.nextSibling();
            }
        } else if (childElement.tagName() == "fx:FRAMES") {
            QDomNode framesChild = child.firstChild();
            while (!framesChild.isNull()) {
#ifndef F_NO_DEBUG
                QLOG_TRACE() << "FXElements::load FRAMES" << childElement.tagName();
#endif
                if (framesChild.toElement().tagName() == "fx:FRAME") {
                    FXFrameTypeCt *frame = new FXFrameTypeCt(m_fibex, this);
                    frame->load(framesChild.toElement());
                    if (!frame->m_id.isEmpty()) {
                        m_frames[frame->m_id] = frame;
                    }
                }
                framesChild = framesChild.nextSibling();
            }
        } else if (childElement.tagName() == "fx:ECUS") {
            QDomNode framesChild = child.firstChild();
            while (!framesChild.isNull()) {
#ifndef F_NO_DEBUG
                QLOG_TRACE() << "FXElements::load ECUS" << childElement.tagName();
#endif
                if (framesChild.toElement().tagName() == "fx:ECU") {
                    FXEcuType *ecu = new FXEcuType(m_fibex, this);
                    ecu->load(framesChild.toElement());
                    if (!ecu->m_id.isEmpty()) {
                        m_ecus[ecu->m_id] = ecu;
                    }
                }
                framesChild = framesChild.nextSibling();
            }
        } else if (childElement.tagName() == "fx:CHANNELS") {
            QDomNode subChild = child.firstChild();
            while (!subChild.isNull()) {
#ifndef F_NO_DEBUG
                QLOG_TRACE() << "FXElements::load CHANNELS" << childElement.tagName();
#endif
                if (subChild.toElement().tagName() == "fx:CHANNEL") {
                    FRChannelType c;
                    c.load(subChild.toElement());
                    m_channelList.append(c);
                }
                subChild = subChild.nextSibling();
            }
        } else if (childElement.tagName() == "fx:CLUSTERS") {
            QDomNode subChild = child.firstChild();
            while (!subChild.isNull()) {
#ifndef F_NO_DEBUG
                QLOG_TRACE() << "FXElements::load CLUSTERS" << childElement.tagName();
#endif
                if (subChild.toElement().tagName() == "fx:CLUSTER") {
                    FRClusterType c;
                    c.load(subChild.toElement());
                    m_clusterList.append(c);
                }
                subChild = subChild.nextSibling();
            }
        } else if (childElement.tagName() == "fx:GATEWAYS") {

        } else if (childElement.tagName() == "fx:FUNCTIONS") {

        } else if (childElement.tagName() == "fx:COMPOSITES") {

        }

        child = child.nextSibling();
    }

    return true;
}

} // FIBEX
} // ASAM

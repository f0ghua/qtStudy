#include "FXElements.h"
#include "LogDb.h"

#include <QDomElement>
#include <QDebug>

namespace ASAM {
namespace FIBEX {

FXElements::Clusters::Clusters()
    : m_clusterList()
{
}

FXElements::Channels::Channels()
    : m_channelList()
{
}

FXElements::Gateways::Gateways()
    : m_gatewayList()
{
}

FXElements::Ecus::Ecus()
    : m_ecuList()
{
}

FXElements::Pdus::Pdus()
    : m_pduList()
{
}

FXElements::Frames::Frames()
    : m_frameList()
{
}

FXElements::Functions::Functions()
    : m_functionList()
{
}

FXElements::Signals::Signals()
    : m_signalList()
{
}

FXElements::Composites::Composites()
    : m_compositeList()
{
}

FXElements::FXElements()
    : m_clusterList()
    , m_channelList()
    , m_gatewayList()
    , m_ecuList()
    , m_pduList()
    , m_frameList()
    , m_functionList()
    , m_signalList()
    , m_compositeList()
{
}

bool FXElements::load(const QDomElement &element)
{
    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
#ifndef F_NO_DEBUG
        QLOG_TRACE() << "FXElements::load" << childElement.tagName();
#endif
        if (childElement.tagName() == "fx:CLUSTERS") {

        } else if (childElement.tagName() == "fx:CHANNELS") {

        } else if (childElement.tagName() == "fx:GATEWAYS") {

        } else if (childElement.tagName() == "fx:ECUS") {
            QDomNode framesChild = child.firstChild();
            while (!framesChild.isNull()) {
#ifndef F_NO_DEBUG
                QLOG_TRACE() << "FXElements::load ECUS" << childElement.tagName();
#endif
                if (framesChild.toElement().tagName() == "fx:ECU") {
                    FXEcuType ecu;
                    ecu.load(framesChild.toElement());
                    m_ecuList.append(ecu);
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
                    FXPduTypeCt pdu;
                    pdu.load(framesChild.toElement());
                    m_pduList.append(pdu);
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
                    FXFrameTypeCt frame;
                    frame.load(framesChild.toElement());
                    m_frameList.append(frame);
                }
                framesChild = framesChild.nextSibling();
            }
        } else if (childElement.tagName() == "fx:FUNCTIONS") {

        } else if (childElement.tagName() == "fx:SIGNALS") {
            QDomNode framesChild = child.firstChild();
            while (!framesChild.isNull()) {
#ifndef F_NO_DEBUG
                QLOG_TRACE() << "FXElements::load SIGNALS" << childElement.tagName();
#endif
                if (framesChild.toElement().tagName() == "fx:SIGNAL") {
                    FXSignalType sig;
                    sig.load(framesChild.toElement());
                    m_signalList.append(sig);
                }
                framesChild = framesChild.nextSibling();
            }
        } else if (childElement.tagName() == "fx:COMPOSITES") {

        }

        child = child.nextSibling();
    }

    return true;
}

}
}

#include "FXElements.h"
#include "LogDb.h"

#include <QDomElement>
#include <QDebug>

namespace ASAM {
namespace FIBEX {

FXElements::Clusters::Clusters()
    : m_cluster()
{
}

FXElements::Channels::Channels()
    : m_channel()
{
}

FXElements::Gateways::Gateways()
    : m_gateway()
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
    : m_function()
{
}

FXElements::Signals::Signals()
    : m_sigList()
{
}

FXElements::Composites::Composites()
    : m_composite()
{
}

FXElements::FXElements()
    : m_clusters()
    , m_channels()
    , m_gateways()
    , m_ecusList()
    , m_pdusList()
    , m_framesList()
    , m_functions()
    , m_signalsList()
    , m_composites()
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
            Ecus ecusObject;

            QDomNode framesChild = child.firstChild();
            while (!framesChild.isNull()) {
#ifndef F_NO_DEBUG
                QLOG_TRACE() << "FXElements::load ECUS" << childElement.tagName();
#endif
                if (framesChild.toElement().tagName() == "fx:ECU") {
                    FXEcuType ecu;
                    ecu.load(framesChild.toElement());
                    ecusObject.m_ecuList.append(ecu);
                }
                framesChild = framesChild.nextSibling();
            }

            m_ecusList.append(ecusObject);

        } else if (childElement.tagName() == "fx:PDUS") {
            Pdus pdusObj;

            QDomNode framesChild = child.firstChild();
            while (!framesChild.isNull()) {
#ifndef F_NO_DEBUG
                QLOG_TRACE() << "FXElements::load PDUS" << childElement.tagName();
#endif
                if (framesChild.toElement().tagName() == "fx:PDU") {
                    FXPduTypeCt pdu;
                    pdu.load(framesChild.toElement());
                    pdusObj.m_pduList.append(pdu);
                }
                framesChild = framesChild.nextSibling();
            }

            m_pdusList.append(pdusObj);
        } else if (childElement.tagName() == "fx:FRAMES") {
            Frames framesObj;

            QDomNode framesChild = child.firstChild();
            while (!framesChild.isNull()) {
#ifndef F_NO_DEBUG
                QLOG_TRACE() << "FXElements::load FRAMES" << childElement.tagName();
#endif
                if (framesChild.toElement().tagName() == "fx:FRAME") {
                    FXFrameTypeCt frame;
                    frame.load(framesChild.toElement());
                    framesObj.m_frameList.append(frame);
                }
                framesChild = framesChild.nextSibling();
            }

            m_framesList.append(framesObj);

        } else if (childElement.tagName() == "fx:FUNCTIONS") {

        } else if (childElement.tagName() == "fx:SIGNALS") {
            Signals signalsObj;

            QDomNode framesChild = child.firstChild();
            while (!framesChild.isNull()) {
#ifndef F_NO_DEBUG
                QLOG_TRACE() << "FXElements::load SIGNALS" << childElement.tagName();
#endif
                if (framesChild.toElement().tagName() == "fx:SIGNAL") {
                    FXSignalType sig;
                    sig.load(framesChild.toElement());
                    signalsObj.m_sigList.append(sig);
                }
                framesChild = framesChild.nextSibling();
            }

            m_signalsList.append(signalsObj);
        } else if (childElement.tagName() == "fx:COMPOSITES") {

        }

        child = child.nextSibling();
    }

    return true;
}

}
}

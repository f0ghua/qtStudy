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
    : m_ecu()
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
    : m_signal()
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
    , m_ecus()
    , m_pdusList()
    , m_framesList()
    , m_functions()
    , m_signals()
    , m_composites()
{
}

bool FXElements::load(const QDomElement &element)
{
    QDomNode child = element.firstChild();
    while (!child.isNull()) {
#ifndef F_NO_DEBUG
        QLOG_TRACE() << "FXElements::load" << child.toElement().tagName();
#endif
        if (child.toElement().tagName() == "fx:CLUSTERS") {

        } else if (child.toElement().tagName() == "fx:CHANNELS") {

        } else if (child.toElement().tagName() == "fx:GATEWAYS") {

        } else if (child.toElement().tagName() == "fx:ECUS") {

        } else if (child.toElement().tagName() == "fx:PDUS") {
            Pdus pdusObj;

            QDomNode framesChild = child.firstChild();
            while (!framesChild.isNull()) {
#ifndef F_NO_DEBUG
                QLOG_TRACE() << "FXElements::load PDUS" << child.toElement().tagName();
#endif
                if (framesChild.toElement().tagName() == "fx:PDU") {
                    FXPduTypeCt pdu;
                    pdu.load(framesChild.toElement());
                    pdusObj.m_pduList.append(pdu);
                }
                framesChild = framesChild.nextSibling();
            }

            m_pdusList.append(pdusObj);
        } else if (child.toElement().tagName() == "fx:FRAMES") {
            Frames framesObj;

            QDomNode framesChild = child.firstChild();
            while (!framesChild.isNull()) {
#ifndef F_NO_DEBUG
                QLOG_TRACE() << "FXElements::load FRAMES" << child.toElement().tagName();
#endif
                if (framesChild.toElement().tagName() == "fx:FRAME") {
                    FXFrameTypeCt frame;
                    frame.load(framesChild.toElement());
                    framesObj.m_frameList.append(frame);
                }
                framesChild = framesChild.nextSibling();
            }

            m_framesList.append(framesObj);

        } else if (child.toElement().tagName() == "fx:FUNCTIONS") {

        } else if (child.toElement().tagName() == "fx:SIGNALS") {

        } else if (child.toElement().tagName() == "fx:COMPOSITES") {

        }

        child = child.nextSibling();
    }

    return true;
}

}
}

#include "Fibex.h"
#include "LogDb.h"

namespace ASAM {
namespace FIBEX {

Fibex::Fibex(QObject *parent)
    : FXFibex(parent)
    , m_domElement(nullptr)
{

}

Fibex::~Fibex()
{

}

bool Fibex::covertXml2Db()
{    
#ifndef F_NO_DEBUG
    QLOG_DEBUG() << "covertXml2Db --------------------------------------------";
#endif

    {
        QHash<QString, CodingType*> &codings = m_processingInformation->m_codings->m_codings;
        QHash<QString, FXSignalType*> &sigs = m_elements->m_signals;
        QHash<QString, FXSignalType*>::const_iterator ci;

        for (ci = sigs.constBegin(); ci != sigs.constEnd(); ci++) {
            FBSignal *fbSignal = new FBSignal(this);
            const FXSignalType *sig = ci.value();
#ifndef F_NO_DEBUG
            QLOG_DEBUG() << ci.key() << sig->m_shortName << sig->m_codingRef;
#endif
            fbSignal->m_name = sig->m_shortName;

            if (!sig->m_codingRef.isEmpty()
                    && codings.contains(sig->m_codingRef)) {
                CodingType *ct = codings.value(sig->m_codingRef);
#ifndef F_NO_DEBUG
                QLOG_DEBUG() << "found codingType" << ct->m_shortName;
#endif

                if (ct->m_codedType) {
                    fbSignal->m_bitSize = ct->m_codedType->m_bitLength;
                    if (ct->m_codedType->m_baseDataType) {
                        fbSignal->m_valueType = *ct->m_codedType->m_baseDataType;
                    }
                }

                if (ct->m_compuMethods
                        && ct->m_compuMethods->m_compuMethods.count() > 0) {
                    HOCompuMethod *cm = ct->m_compuMethods->m_compuMethods.at(0);
#ifndef F_NO_DEBUG
                    QLOG_DEBUG() << QObject::tr("m_compuCategory = %1").arg((int)cm->m_compuCategory);
#endif
                    if (cm->m_physConstrs) {
                        if (cm->m_physConstrs->m_scaleConstr->m_lowerLimit) {
                            fbSignal->m_minimumPhysicalValue = *cm->m_physConstrs->m_scaleConstr->m_lowerLimit;
                        }
                        if (cm->m_physConstrs->m_scaleConstr->m_upperLimit) {
                            fbSignal->m_maximumPhysicalValue = *cm->m_physConstrs->m_scaleConstr->m_upperLimit;
                        }
                    }

                    switch (cm->m_compuCategory) {
                        case FibexTypes::HOCompuCategorySt::LINEAR: {
                            if (cm->m_compuInternalToPhys
                                    && (cm->m_compuInternalToPhys->m_compuScales.count() > 0)
                                    && cm->m_compuInternalToPhys->m_compuScales.at(0)->m_compuRationalCoeffs) {
                                HOCompuRationalCoeffs *crf = cm->m_compuInternalToPhys->m_compuScales.at(0)->m_compuRationalCoeffs;
                                if ((crf->m_compuNumeratorList.count() >= 2)
                                        && crf->m_compuDenominatorList.count() > 0) {
                                    fbSignal->m_factor = crf->m_compuNumeratorList.at(1)/crf->m_compuDenominatorList.at(0);
                                    fbSignal->m_offset = crf->m_compuNumeratorList.at(0)/crf->m_compuDenominatorList.at(0);
                                }
                            }
                            break;
                        }
                        case FibexTypes::HOCompuCategorySt::IDENTICAL: {
                            fbSignal->m_factor = 1;
                            fbSignal->m_offset = 0;
                            break;
                        }
                        case FibexTypes::HOCompuCategorySt::TEXTTABLE: {
                            fbSignal->m_factor = 1;
                            fbSignal->m_offset = 0;
                            if (cm->m_compuInternalToPhys
                                    && (cm->m_compuInternalToPhys->m_compuScales.count() > 0)) {
                                foreach (HOCompuScale *cs, cm->m_compuInternalToPhys->m_compuScales) {
                                    if (cs->m_lowerLimit) {
                                        fbSignal->m_valueDescriptions.insert(*cs->m_lowerLimit, cs->m_compuConst.m_vt);
                                    }
                                }
                            }
                            break;
                        }
                        default:
                            break;
                    }
                }
            }

            m_signals[ci.key()] = fbSignal;
        }

    }

    {
        QHash<QString, FXPduTypeCt*> &pdus = m_elements->m_pdus;
        QHash<QString, FXPduTypeCt*>::const_iterator ci;
        for (ci = pdus.constBegin(); ci != pdus.constEnd(); ci++) {
            FBPdu *fbPdu = new FBPdu(this);
            const FXPduTypeCt *pdu = ci.value();

            fbPdu->m_shortName = pdu->m_shortName;
            fbPdu->m_byteLength = pdu->m_byteLength;
            fbPdu->m_type = pdu->m_pduType;

            if (pdu->m_sigInstances
                    && pdu->m_sigInstances->m_sigInstances.count() > 0) {
                QHash<QString, FXSignalInstanceType*> &sigInstances =
                        pdu->m_sigInstances->m_sigInstances;
                QHash<QString, FXSignalInstanceType*>::const_iterator ciSig;
                for (ciSig = sigInstances.constBegin();
                     ciSig != sigInstances.constEnd(); ciSig++) {
                    FXSignalInstanceType *si = ciSig.value();
                    if (m_signals.contains(si->m_sigRef.m_idRef)) {
                        FBSignal *fbSignal = m_signals[si->m_sigRef.m_idRef];
                        fbSignal->m_startBit = si->m_commLayoutDetails.m_bitPostion;
                        fbSignal->m_isBigEndian = si->m_commLayoutDetails.m_isBigEndian;
                    }
                }
            }

            m_pdus[pdu->m_id] = fbPdu;
        }
    }

    {
        QHash<QString, FXFrameTypeCt*> &frames = m_elements->m_frames;
        QHash<QString, FXFrameTypeCt*>::const_iterator ci;
        for (ci = frames.constBegin(); ci != frames.constEnd(); ci++) {
            FBFrame *fbFrame = new FBFrame(this);
            const FXFrameTypeCt *fxFrame = ci.value();

            fbFrame->m_fxFrame = fxFrame;

            if (fxFrame->m_pduInstances
                    && fxFrame->m_pduInstances->m_pduInstances.count() > 0) {
                QHash<QString, FXPduInstanceType*> &instances =
                        fxFrame->m_pduInstances->m_pduInstances;
                QHash<QString, FXPduInstanceType*>::const_iterator ciPdu;
                for (ciPdu = instances.constBegin();
                     ciPdu != instances.constEnd(); ciPdu++) {
                    FXPduInstanceType *ist = ciPdu.value();
                    if (m_pdus.contains(ist->m_idRef)) {
                        FBPdu *fbPdu = m_pdus[ist->m_idRef];
                        fbPdu->m_startBit = ist->m_commLayoutDetails.m_bitPostion;
                        fbPdu->m_isBigEndian = ist->m_commLayoutDetails.m_isBigEndian;

                        fbFrame->m_pdus[ist->m_idRef] = fbPdu;
                    }
                }
            }

            m_frames[fxFrame->m_id] = fbFrame;
        }
    }

    {
        QHash<QString, FRChannelType*> &channels = m_elements->m_channels;
        QHash<QString, FRChannelType*>::const_iterator ci;
        for (ci = channels.constBegin(); ci != channels.constEnd(); ci++) {
            FBChannel *fbChannel = new FBChannel(this);
            const FRChannelType *frChannel = ci.value();

            fbChannel->m_frChannel = frChannel;

            foreach (const FXFrameTriggeringType *t, frChannel->m_frameTriggerings) {
                FBFrameTriggering *fbTriggering = new FBFrameTriggering(this);
                fbChannel->m_frameTriggerings[t->m_id] = fbTriggering;

                FBFrame *fbFrame = NULL;
                if (m_frames.contains(t->m_frameRef)) {
                    fbFrame = m_frames.value(t->m_frameRef);
                }
                if (!fbFrame) { // we will update the frame which has been found
                    continue;
                }
                fbTriggering->m_frames[t->m_frameRef] = fbFrame;

                if (t->m_timings) {
                    foreach (FXAbsolutelyScheduledTimingType *rst, t->m_timings->m_absolutelyScheduledTimings) {
                        // @TODO If there are more than 1 timing, we should new frames except the first one
                        fbFrame->m_slotId = rst->m_slotId;
                        fbFrame->m_baseCycle = rst->m_baseCycle;
                        fbFrame->m_cycleCounter = rst->m_cycleCounter;
                        fbFrame->m_cycleRepetition = rst->m_cycleRepetition;
                    }
                }
            }

            foreach (const FXPduTriggeringType *t, frChannel->m_pduTriggerings) {
                FBPduTriggering *fbTriggering = new FBPduTriggering(this);
                fbChannel->m_pduTriggerings[t->m_id] = fbTriggering;
                if (m_pdus.contains(t->m_pduRef)) {
                    fbTriggering->m_pdus[t->m_pduRef] = m_pdus.value(t->m_pduRef);
                }
            }

            m_channels[frChannel->m_id] = fbChannel;
        }
    }

    {
        QHash<QString, FXEcuType*> &ecus = m_elements->m_ecus;
        QHash<QString, FXEcuType*>::const_iterator ci;
        for (ci = ecus.constBegin(); ci != ecus.constEnd(); ci++) {
            FBEcu *fbEcu = new FBEcu(this);
            const FXEcuType *fxEcu = ci.value();

            fbEcu->m_fxEcu = fxEcu;

            foreach (const FRConnectorType *connector, fxEcu->m_connectors) {
                FBChannel *fbChannel;
                if (m_channels.contains(connector->m_channelRef)) {
                    fbChannel = m_channels.value(connector->m_channelRef);
                }

                foreach (const FXEcuPortType *port, connector->m_inputPorts) {
                    if (fbChannel) {
                        if (fbChannel->m_frameTriggerings.contains(port->m_frameTriggeringRef)) {
                            FBFrameTriggering *tr = fbChannel->m_frameTriggerings.value(port->m_frameTriggeringRef);
                            fbEcu->m_inputFrames.unite(tr->m_frames);
                        }
                    }

                    foreach (FXIncludedPduType *pdu, port->m_includedPdus) {
                        if (fbChannel) {
                            if (fbChannel->m_pduTriggerings.contains(pdu->m_pduTriggeringRef)) {
                                FBPduTriggering *tr = fbChannel->m_pduTriggerings.value(pdu->m_pduTriggeringRef);
                                fbEcu->m_inputPdus.unite(tr->m_pdus);
                            }
                        }
                    }
                }

                foreach (const FXEcuPortType *port, connector->m_outputPorts) {
                    if (fbChannel) {
                        if (fbChannel->m_frameTriggerings.contains(port->m_frameTriggeringRef)) {
                            FBFrameTriggering *tr = fbChannel->m_frameTriggerings.value(port->m_frameTriggeringRef);
                            fbEcu->m_outputFrames.unite(tr->m_frames);
                        }
                    }

                }
            }

            m_ecus[fxEcu->m_id] = fbEcu;
        }
    }

    {
        int count = 0;
        foreach (auto fbSignal, m_signals) {
#ifndef F_NO_DEBUG
            QLOG_DEBUG() << QObject::tr(
                                "m_signals name = %1 factor = %2, offset = %3, "
                                "min = %4, max = %5, startbit = %6, bitsize = %7, isbig = %8"
                            ).\
                            arg(fbSignal->m_name).\
                            arg(fbSignal->m_factor).\
                            arg(fbSignal->m_offset).\
                            arg(fbSignal->m_minimumPhysicalValue).\
                            arg(fbSignal->m_maximumPhysicalValue).\
                            arg(fbSignal->m_startBit).\
                            arg(fbSignal->m_bitSize).\
                            arg(fbSignal->m_isBigEndian) << fbSignal->m_valueDescriptions;
#endif
            count++;
        }
#ifndef F_NO_DEBUG
        QLOG_INFO() << "Fibex::covertXml2Db signal count =" << count;
#endif

        count = 0;
        foreach (auto fbPdu, m_pdus) {
#ifndef F_NO_DEBUG
            QLOG_DEBUG() << QObject::tr(
                                "m_pdus name = %1 byteLength = %2, type = %3, "
                                "startbit = %4, isBigEndian = %5"
                            ).\
                            arg(fbPdu->m_shortName).\
                            arg(fbPdu->m_byteLength).\
                            arg((int)fbPdu->m_type).\
                            arg(fbPdu->m_startBit).\
                            arg(fbPdu->m_isBigEndian);
#endif
        }
#ifndef F_NO_DEBUG
        QLOG_INFO() << "Fibex::covertXml2Db pdu count =" << count;
#endif

        count = 0;
        foreach (auto fbFrame, m_frames) {
#ifndef F_NO_DEBUG
            QLOG_DEBUG() << QObject::tr(
                                "m_frames name = %1 byteLength = %2, type = %3, "
                                "m_slotId = %4, m_baseCycle = %5, m_cycleCounter = %6, "
                                "m_cycleRepetition = %7, pduCount = %8"
                            ).\
                            arg(fbFrame->m_shortName).\
                            arg(fbFrame->m_byteLength).\
                            arg((int)fbFrame->m_type).\
                            arg(fbFrame->m_slotId).\
                            arg(fbFrame->m_baseCycle).\
                            arg(fbFrame->m_cycleCounter).\
                            arg(fbFrame->m_cycleRepetition).\
                            arg(fbFrame->m_pdus.count());
#endif
            count++;
        }
#ifndef F_NO_DEBUG
        QLOG_INFO() << "Fibex::covertXml2Db frame count =" << count;
#endif
    }

    return true;
}

bool Fibex::load(const QDomElement &element)
{   
    bool ret;

    /* load Fibex tree */
    ret = FXFibex::load(element);
    if (!ret) {
        return false;
    }

    return covertXml2Db();
}

} // FIBEX
} // ASAM

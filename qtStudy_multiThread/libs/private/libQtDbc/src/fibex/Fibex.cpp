#include "Fibex.h"
#include "LogDb.h"

namespace ASAM {
namespace FIBEX {

Fibex::Fibex()
    : FXFibex()
    , m_domElement(nullptr)
{

}

Fibex::~Fibex()
{
    qDeleteAll(m_ecus);
    m_ecus.clear();

    qDeleteAll(m_channels);
    m_channels.clear();

    qDeleteAll(m_frames);
    m_frames.clear();

    qDeleteAll(m_pdus);
    m_pdus.clear();

    qDeleteAll(m_signals);
    m_signals.clear();
}

bool Fibex::covertXml2Db()
{    
#ifndef F_NO_DEBUG
    QLOG_DEBUG() << "covertXml2Db --------------------------------------------";
#endif

    {
        QHash<QString, FXSignalType*> &sigs = m_elements->m_signals;
        QHash<QString, FXSignalType*>::const_iterator ci;

        for (ci = sigs.constBegin(); ci != sigs.constEnd(); ci++) {
            FBSignal *fbSignal = new FBSignal();
            m_signals[ci.key()] = fbSignal;
            const FXSignalType *fxSignal = ci.value();
            fbSignal->m_fxSignal = fxSignal;

#ifndef F_NO_DEBUG
            //QLOG_DEBUG() << ci.key() << fxSignal->m_shortName << fxSignal->m_codingRef;
#endif
            if (fxSignal->m_sigType) {
                fbSignal->m_signalType = &fxSignal->m_sigType->m_type;
            }

            if (!m_processingInformation->m_codings) {
                continue;
            }

            QHash<QString, CodingType*> &codings = m_processingInformation->m_codings->m_codings;

            if (!fxSignal->m_codingRef.isEmpty()
                    && codings.contains(fxSignal->m_codingRef)) {
                CodingType *ct = codings.value(fxSignal->m_codingRef);
#ifndef F_NO_DEBUG
                //QLOG_DEBUG() << "found codingType" << ct->m_shortName;
#endif

                if (ct->m_codedType) {
                    fbSignal->m_bitSize = ct->m_codedType->m_bitLength;
                    if (ct->m_codedType->m_baseDataType) {
                        fbSignal->m_codedType = *ct->m_codedType->m_baseDataType;
                    }
                }

                if (ct->m_compuMethods
                        && ct->m_compuMethods->m_compuMethods.count() > 0) {
                    HOCompuMethod *cm = ct->m_compuMethods->m_compuMethods.at(0);
#ifndef F_NO_DEBUG
                    //QLOG_DEBUG() << QObject::tr("m_compuCategory = %1").arg((int)cm->m_compuCategory);
#endif
                    if (cm->m_unitRef
                            && (m_processingInformation->m_codings)) {
                        QHash<QString, HOUnit*> &units = m_processingInformation->m_unitSpec->m_units;
                        if (units.contains(*cm->m_unitRef)) {
                            HOUnit *unit = units.value(*cm->m_unitRef);
                            if (unit->m_displayName) {
                                fbSignal->m_unit = *unit->m_displayName;
                            }
                        }
                    }

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
        }

    }

    {
        QHash<QString, FXPduTypeCt*> &pdus = m_elements->m_pdus;
        QHash<QString, FXPduTypeCt*>::const_iterator ci;
        for (ci = pdus.constBegin(); ci != pdus.constEnd(); ci++) {
            FBPdu *fbPdu = new FBPdu();
            const FXPduTypeCt *fxPdu = ci.value();

            fbPdu->m_fxPdu = fxPdu;

            if (fxPdu->m_sigInstances
                    && fxPdu->m_sigInstances->m_sigInstances.count() > 0) {
                QHash<QString, FXSignalInstanceType*> &sigInstances =
                        fxPdu->m_sigInstances->m_sigInstances;
                QHash<QString, FXSignalInstanceType*>::const_iterator ciSig;
                for (ciSig = sigInstances.constBegin();
                     ciSig != sigInstances.constEnd(); ciSig++) {
                    FXSignalInstanceType *si = ciSig.value();
                    if (m_signals.contains(si->m_sigRef.m_idRef)) {
                        FBSignal *fbSignal = m_signals[si->m_sigRef.m_idRef];
                        fbSignal->m_startBit = si->m_commLayoutDetails.m_bitPostion;
                        fbSignal->m_isBigEndian = si->m_commLayoutDetails.m_isBigEndian;
                        fbSignal->m_signalUpdateBitPosition = si->m_signalUpdateBitPosition;

                        fbPdu->m_signals[si->m_sigRef.m_idRef] = fbSignal;
                    }

                }
            }

            m_pdus[fxPdu->m_id] = fbPdu;
        }
    }

    {
        QHash<QString, FXFrameTypeCt*> &frames = m_elements->m_frames;
        QHash<QString, FXFrameTypeCt*>::const_iterator ci;
        for (ci = frames.constBegin(); ci != frames.constEnd(); ci++) {
            FBFrame *fbFrame = new FBFrame();
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
                        fbFrame->m_signals.unite(fbPdu->m_signals);
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
            FBChannel *fbChannel = new FBChannel();
            const FRChannelType *frChannel = ci.value();

            fbChannel->m_frChannel = frChannel;

            foreach (const FXFrameTriggeringType *t, frChannel->m_frameTriggerings) {
                FBFrameTriggering *fbTriggering = new FBFrameTriggering();
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
                        fbFrame->m_cycleRepetition = rst->m_cycleRepetition;
                        fbFrame->m_cycleCounter = rst->m_cycleCounter;

                        FibexFrameKey key(fbFrame->m_slotId, fbFrame->m_baseCycle, fbFrame->m_cycleRepetition);
                        fbChannel->m_frames[key] = fbFrame;

                        break;
                    }
                }
            }

            foreach (const FXPduTriggeringType *t, frChannel->m_pduTriggerings) {
                FBPduTriggering *fbTriggering = new FBPduTriggering();
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
            FBEcu *fbEcu = new FBEcu();
            const FXEcuType *fxEcu = ci.value();

            m_ecus[fxEcu->m_id] = fbEcu;
            fbEcu->m_fxEcu = fxEcu;

            foreach (const FRConnectorType *connector, fxEcu->m_connectors) {
                FBChannel *fbChannel;
                if (m_channels.contains(connector->m_channelRef)) {
                    fbChannel = m_channels.value(connector->m_channelRef);
                }
                if (!fbChannel) continue;

                fbChannel->m_ecus[fxEcu->m_id] = fbEcu;

                foreach (const FXEcuPortType *port, connector->m_inputPorts) {
                    if (fbChannel->m_frameTriggerings.contains(port->m_frameTriggeringRef)) {
                        FBFrameTriggering *tr = fbChannel->m_frameTriggerings.value(port->m_frameTriggeringRef);
                        fbEcu->m_inputFrames.unite(tr->m_frames);
                    }

                    foreach (FXIncludedPduType *pdu, port->m_includedPdus) {
                        if (fbChannel->m_pduTriggerings.contains(pdu->m_pduTriggeringRef)) {
                            FBPduTriggering *tr = fbChannel->m_pduTriggerings.value(pdu->m_pduTriggeringRef);
                            fbEcu->m_inputPdus.unite(tr->m_pdus);
                        }

                    }
                }

                foreach (const FXEcuPortType *port, connector->m_outputPorts) {
                    if (fbChannel->m_frameTriggerings.contains(port->m_frameTriggeringRef)) {
                        FBFrameTriggering *tr = fbChannel->m_frameTriggerings.value(port->m_frameTriggeringRef);
                        fbEcu->m_outputFrames.unite(tr->m_frames);
                    }
                }
            } 
        }
    }


    {
        int count = 0;
#if 0
        foreach (auto fbSignal, m_signals) {
            QLOG_DEBUG() << *fbSignal;
            count++;
        }
        QLOG_INFO() << "Fibex::covertXml2Db signal count =" << count;


        count = 0;
        foreach (const FBPdu *fbPdu, m_pdus) {
            QLOG_DEBUG() << *fbPdu;
        }
        QLOG_INFO() << "Fibex::covertXml2Db pdu count =" << count;


        count = 0;
        foreach (const FBFrame *fbFrame, m_frames) {
            QLOG_DEBUG() << *fbFrame;
            count++;
        }

        QLOG_INFO() << "Fibex::covertXml2Db frame count =" << count;

#endif // if 0

        count = 0;
        foreach (const FBChannel *fbChannel, m_channels) {
            QLOG_DEBUG() << *fbChannel;

            foreach (const FBFrame *fbFrame, fbChannel->m_frames) {
                QLOG_DEBUG() << *fbFrame;

                foreach (const FBPdu *fbPdu, fbFrame->m_pdus) {
                    QLOG_DEBUG() << *fbPdu;
                }

                foreach (const FBSignal *fbSignal, fbFrame->m_signals) {
                    QLOG_DEBUG() << *fbSignal;
                }
            }

            foreach (const FBEcu *fbEcu, fbChannel->m_ecus) {
                QLOG_DEBUG() << *fbEcu;

                QLOG_DEBUG() << "ecu" << fbEcu->name() << "input frames:" << fbEcu->m_inputFrames.count();
                foreach (auto fbFrame, fbEcu->m_inputFrames) {
                    QLOG_DEBUG() << *fbFrame;
                }

                QLOG_DEBUG() << "ecu" << fbEcu->name() << "output frames:" << fbEcu->m_outputFrames.count();
                foreach (auto fbFrame, fbEcu->m_outputFrames) {
                    QLOG_DEBUG() << *fbFrame;
                }
            }

            count++;
        }

        QLOG_INFO() << "Fibex::covertXml2Db channel count =" << count;

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

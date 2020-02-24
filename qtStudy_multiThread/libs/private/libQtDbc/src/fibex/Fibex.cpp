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
    int count = 0;
#ifndef F_NO_DEBUG
    QLOG_DEBUG() << "covertXml2Db --------------------------------------------";
#endif

    {
        QHash<QString, CodingType*> &codings = m_processingInformation->m_codings->m_codings;
        QHash<QString, FXSignalType*> &sigs = m_elements->m_signals;
        QHash<QString, FXSignalType*>::const_iterator ci;
        count = 0;
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

                    fbSignal->m_minimumPhysicalValue = cm->m_physConstrs.m_scaleConstr.m_lowerLimit;
                    fbSignal->m_maximumPhysicalValue = cm->m_physConstrs.m_scaleConstr.m_upperLimit;

                    switch (cm->m_compuCategory) {
                        case FibexTypes::HOCompuCategorySt::LINEAR:
                        {
                            if (cm->m_compuInternalToPhys
                                    && (cm->m_compuInternalToPhys->m_compuScales.count() >= 1)
                                    && cm->m_compuInternalToPhys->m_compuScales.at(0)->m_compuRationalCoeffs) {
                                HOCompuRationalCoeffs *crf = cm->m_compuInternalToPhys->m_compuScales.at(0)->m_compuRationalCoeffs;
                                if ((crf->m_compuNumeratorList.count() >= 2)
                                        && crf->m_compuDenominatorList.count() >= 1) {
                                    fbSignal->m_factor = crf->m_compuNumeratorList.at(1)/crf->m_compuDenominatorList.at(0);
                                    fbSignal->m_offset = crf->m_compuNumeratorList.at(0)/crf->m_compuDenominatorList.at(0);
                                }
                            }
                            break;
                        }
                        case FibexTypes::HOCompuCategorySt::IDENTICAL:
                            break;
                        default:
                            break;
                    }
                }
            }

            m_signals[ci.key()] = fbSignal;

#ifndef F_NO_DEBUG
            QLOG_DEBUG() << QObject::tr("m_signals factor = %1, offset = %2, min = %3, max = %4").\
                            arg(fbSignal->m_factor).\
                            arg(fbSignal->m_offset).\
                            arg(fbSignal->m_minimumPhysicalValue).\
                            arg(fbSignal->m_maximumPhysicalValue);
#endif
            count++;
        }
#ifndef F_NO_DEBUG
        QLOG_INFO() << "Fibex::covertXml2Db signal count =" << count;
#endif
    }

    {
        QHash<QString, FXPduTypeCt*> &pdus = m_elements->m_pdus;
        QHash<QString, FXPduTypeCt*>::const_iterator ci;
        count = 0;
        for (ci = pdus.constBegin(); ci != pdus.constEnd(); ci++) {
            //FBSignal *fbSignal = new FBSignal(this);
            const FXPduTypeCt *pdu = ci.value();

            count++;
        }

#ifndef F_NO_DEBUG
        QLOG_INFO() << "Fibex::covertXml2Db pdu count =" << count;
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

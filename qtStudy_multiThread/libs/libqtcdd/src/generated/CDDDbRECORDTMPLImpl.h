#ifndef VECTOR_CDD_CDDDBRECORDTMPLIMPL_H
#define VECTOR_CDD_CDDDBRECORDTMPLIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbCVALUETYPE;
class CDDDbENUMRECORDITEMTMPL;
class CDDDbPVALUETYPE;
class CDDDbTRRECORDITEMTMPL;
class CDDDbUNSRECORDITEMTMPL;

/**
 * @brief element RECORDTMPL
 *
 */
class VECTOR_CDD_API CDDDbRECORDTMPLImpl
{
public:
    CDDDbRECORDTMPLImpl();
    ~CDDDbRECORDTMPLImpl();

    void load(const QDomElement &element);

    /** @attribute spec */
    QString m_spec;

    QString m_text;

    /** @element CVALUETYPE */
    QSharedPointer<CDDDbCVALUETYPE> m_elCvaluetype;

    /** @element ENUMRECORDITEMTMPL */
    QMap<QString, QSharedPointer<CDDDbENUMRECORDITEMTMPL>> m_elEnumrecorditemtmpls;

    /** @element PVALUETYPE */
    QSharedPointer<CDDDbPVALUETYPE> m_elPvaluetype;

    /** @element TRRECORDITEMTMPL */
    QMap<QString, QSharedPointer<CDDDbTRRECORDITEMTMPL>> m_elTrrecorditemtmpls;

    /** @element UNSRECORDITEMTMPL */
    QMap<QString, QSharedPointer<CDDDbUNSRECORDITEMTMPL>> m_elUnsrecorditemtmpls;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBRECORDTMPLIMPL_H

#ifndef VECTOR_CDD_CDDDBRECORDTMPL_H
#define VECTOR_CDD_CDDDBRECORDTMPL_H

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
class VECTOR_CDD_API CDDDbRECORDTMPL
{
public:
    CDDDbRECORDTMPL();
    ~CDDDbRECORDTMPL();

    void load(const QDomElement &element);

    /** @attribute spec */
    QString m_spec;

    /** @element CVALUETYPE */
    QSharedPointer<CDDDbCVALUETYPE> m_cvaluetype;

    /** @element ENUMRECORDITEMTMPL */
    QMap<QString, QSharedPointer<CDDDbENUMRECORDITEMTMPL>> m_enumrecorditemtmpls;

    /** @element PVALUETYPE */
    QSharedPointer<CDDDbPVALUETYPE> m_pvaluetype;

    /** @element TRRECORDITEMTMPL */
    QMap<QString, QSharedPointer<CDDDbTRRECORDITEMTMPL>> m_trrecorditemtmpls;

    /** @element UNSRECORDITEMTMPL */
    QMap<QString, QSharedPointer<CDDDbUNSRECORDITEMTMPL>> m_unsrecorditemtmpls;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBRECORDTMPL_H

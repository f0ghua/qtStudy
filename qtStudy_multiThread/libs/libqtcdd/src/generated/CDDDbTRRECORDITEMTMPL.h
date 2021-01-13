#ifndef VECTOR_CDD_CDDDBTRRECORDITEMTMPL_H
#define VECTOR_CDD_CDDDBTRRECORDITEMTMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbNAME;
class CDDDbQUAL;

/**
 * @brief element TRRECORDITEMTMPL
 *
 */
class VECTOR_CDD_API CDDDbTRRECORDITEMTMPL
{
public:
    CDDDbTRRECORDITEMTMPL();
    ~CDDDbTRRECORDITEMTMPL();

    void load(const QDomElement &element);

    /** @attribute conv */
    QString m_conv;

    /** @attribute id */
    QString m_id;

    /** @attribute mayBeDup */
    QString m_mayBeDup;

    /** @attribute oid */
    QString m_oid;

    /** @attribute temploid */
    QString m_temploid;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_name;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_qual;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBTRRECORDITEMTMPL_H

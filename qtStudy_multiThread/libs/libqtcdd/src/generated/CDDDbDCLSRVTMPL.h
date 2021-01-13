#ifndef VECTOR_CDD_CDDDBDCLSRVTMPL_H
#define VECTOR_CDD_CDDDBDCLSRVTMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbNAME;
class CDDDbQUAL;

/**
 * @brief element DCLSRVTMPL
 *
 */
class VECTOR_CDD_API CDDDbDCLSRVTMPL
{
public:
    CDDDbDCLSRVTMPL();
    ~CDDDbDCLSRVTMPL();

    void load(const QDomElement &element);

    /** @attribute conv */
    QString m_conv;

    /** @attribute dtref */
    QString m_dtref;

    /** @attribute id */
    QString m_id;

    /** @attribute oid */
    QString m_oid;

    /** @attribute temploid */
    QString m_temploid;

    /** @attribute tmplref */
    QString m_tmplref;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_name;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_qual;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDCLSRVTMPL_H

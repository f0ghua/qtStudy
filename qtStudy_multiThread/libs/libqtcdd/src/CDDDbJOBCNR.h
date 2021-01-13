#ifndef VECTOR_CDD_CDDDBJOBCNR_H
#define VECTOR_CDD_CDDDBJOBCNR_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbNAME;
class CDDDbQUAL;

/**
 * @brief element JOBCNR
 *
 */
class VECTOR_CDD_API CDDDbJOBCNR
{
public:
    CDDDbJOBCNR();
    ~CDDDbJOBCNR();

    void load(const QDomElement &element);

    /** @attribute id */
    QString m_id;

    /** @attribute oid */
    QString m_oid;

    /** @attribute req */
    QString m_req;

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

#endif // VECTOR_CDD_CDDDBJOBCNR_H

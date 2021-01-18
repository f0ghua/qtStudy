#ifndef VECTOR_CDD_CDDDBJOBCNRIMPL_H
#define VECTOR_CDD_CDDDBJOBCNRIMPL_H

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
class VECTOR_CDD_API CDDDbJOBCNRImpl
{
public:
    CDDDbJOBCNRImpl();
    ~CDDDbJOBCNRImpl();

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

    QString m_text;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_elName;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_elQual;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBJOBCNRIMPL_H

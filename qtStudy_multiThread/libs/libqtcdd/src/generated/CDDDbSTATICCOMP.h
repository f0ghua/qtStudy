#ifndef VECTOR_CDD_CDDDBSTATICCOMP_H
#define VECTOR_CDD_CDDDBSTATICCOMP_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbNAME;
class CDDDbQUAL;

/**
 * @brief element STATICCOMP
 *
 */
class VECTOR_CDD_API CDDDbSTATICCOMP
{
public:
    CDDDbSTATICCOMP();
    ~CDDDbSTATICCOMP();

    void load(const QDomElement &element);

    /** @attribute dtref */
    QString m_dtref;

    /** @attribute id */
    QString m_id;

    /** @attribute must */
    QString m_must;

    /** @attribute oid */
    QString m_oid;

    /** @attribute spec */
    QString m_spec;

    /** @attribute temploid */
    QString m_temploid;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_name;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_qual;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSTATICCOMP_H

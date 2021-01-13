#ifndef VECTOR_CDD_CDDDBCONSTCOMP_H
#define VECTOR_CDD_CDDDBCONSTCOMP_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbNAME;
class CDDDbQUAL;

/**
 * @brief element CONSTCOMP
 *
 */
class VECTOR_CDD_API CDDDbCONSTCOMP
{
public:
    CDDDbCONSTCOMP();
    ~CDDDbCONSTCOMP();

    void load(const QDomElement &element);

    /** @attribute bl */
    QString m_bl;

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

    /** @attribute v */
    QString m_v;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_name;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_qual;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBCONSTCOMP_H

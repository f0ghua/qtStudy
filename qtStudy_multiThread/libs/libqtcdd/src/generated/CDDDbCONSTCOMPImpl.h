#ifndef VECTOR_CDD_CDDDBCONSTCOMPIMPL_H
#define VECTOR_CDD_CDDDBCONSTCOMPIMPL_H

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
class VECTOR_CDD_API CDDDbCONSTCOMPImpl
{
public:
    CDDDbCONSTCOMPImpl();
    ~CDDDbCONSTCOMPImpl();

    void load(const QDomElement &element);

    /** @attribute bl */
    QString m_bl;

    /** @attribute id */
    QString m_id;

    /** @attribute must */
    QString m_must;

    /** @attribute oid */
    QString m_oid;

    /** @attribute respsupbit */
    QString m_respsupbit;

    /** @attribute spec */
    QString m_spec;

    /** @attribute temploid */
    QString m_temploid;

    /** @attribute v */
    QString m_v;

    QString m_text;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_elName;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_elQual;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBCONSTCOMPIMPL_H

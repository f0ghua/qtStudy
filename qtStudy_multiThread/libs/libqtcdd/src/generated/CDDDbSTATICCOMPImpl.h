#ifndef VECTOR_CDD_CDDDBSTATICCOMPIMPL_H
#define VECTOR_CDD_CDDDBSTATICCOMPIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbDESC;
class CDDDbNAME;
class CDDDbQUAL;

/**
 * @brief element STATICCOMP
 *
 */
class VECTOR_CDD_API CDDDbSTATICCOMPImpl
{
public:
    CDDDbSTATICCOMPImpl();
    ~CDDDbSTATICCOMPImpl();

    void load(const QDomElement &element);

    /** @attribute dtref */
    QString m_dtref;

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

    QString m_text;

    /** @element DESC */
    QSharedPointer<CDDDbDESC> m_elDesc;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_elName;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_elQual;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSTATICCOMPIMPL_H

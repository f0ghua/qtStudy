#ifndef VECTOR_CDD_CDDDBCONTENTCOMPIMPL_H
#define VECTOR_CDD_CDDDBCONTENTCOMPIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbNAME;
class CDDDbQUAL;
class CDDDbSIMPLECOMPCONT;

/**
 * @brief element CONTENTCOMP
 *
 */
class VECTOR_CDD_API CDDDbCONTENTCOMPImpl
{
public:
    CDDDbCONTENTCOMPImpl();
    ~CDDDbCONTENTCOMPImpl();

    void load(const QDomElement &element);

    /** @attribute id */
    QString m_id;

    /** @attribute must */
    QString m_must;

    /** @attribute oid */
    QString m_oid;

    /** @attribute temploid */
    QString m_temploid;

    QString m_text;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_elName;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_elQual;

    /** @element SIMPLECOMPCONT */
    QVector<QSharedPointer<CDDDbSIMPLECOMPCONT>> m_elSimplecompconts;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBCONTENTCOMPIMPL_H

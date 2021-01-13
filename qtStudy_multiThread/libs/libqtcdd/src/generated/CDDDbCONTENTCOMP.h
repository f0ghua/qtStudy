#ifndef VECTOR_CDD_CDDDBCONTENTCOMP_H
#define VECTOR_CDD_CDDDBCONTENTCOMP_H

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
class VECTOR_CDD_API CDDDbCONTENTCOMP
{
public:
    CDDDbCONTENTCOMP();
    ~CDDDbCONTENTCOMP();

    void load(const QDomElement &element);

    /** @attribute id */
    QString m_id;

    /** @attribute must */
    QString m_must;

    /** @attribute oid */
    QString m_oid;

    /** @attribute temploid */
    QString m_temploid;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_name;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_qual;

    /** @element SIMPLECOMPCONT */
    QSharedPointer<CDDDbSIMPLECOMPCONT> m_simplecompcont;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBCONTENTCOMP_H

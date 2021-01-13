#ifndef VECTOR_CDD_CDDDBREQ_H
#define VECTOR_CDD_CDDDBREQ_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbCONSTCOMP;
class CDDDbNAME;
class CDDDbQUAL;
class CDDDbSTATICCOMP;

/**
 * @brief element REQ
 *
 */
class VECTOR_CDD_API CDDDbREQ
{
public:
    CDDDbREQ();
    ~CDDDbREQ();

    void load(const QDomElement &element);

    /** @attribute oid */
    QString m_oid;

    /** @attribute temploid */
    QString m_temploid;

    /** @element CONSTCOMP */
    QMap<QString, QSharedPointer<CDDDbCONSTCOMP>> m_constcomps;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_name;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_qual;

    /** @element STATICCOMP */
    QSharedPointer<CDDDbSTATICCOMP> m_staticcomp;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBREQ_H

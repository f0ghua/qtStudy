#ifndef VECTOR_CDD_CDDDBPOS_H
#define VECTOR_CDD_CDDDBPOS_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbCONSTCOMP;
class CDDDbNAME;
class CDDDbQUAL;
class CDDDbSIMPLEPROXYCOMP;
class CDDDbSTATICCOMP;

/**
 * @brief element POS
 *
 */
class VECTOR_CDD_API CDDDbPOS
{
public:
    CDDDbPOS();
    ~CDDDbPOS();

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

    /** @element SIMPLEPROXYCOMP */
    QSharedPointer<CDDDbSIMPLEPROXYCOMP> m_simpleproxycomp;

    /** @element STATICCOMP */
    QSharedPointer<CDDDbSTATICCOMP> m_staticcomp;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBPOS_H

#ifndef VECTOR_CDD_CDDDBPOSIMPL_H
#define VECTOR_CDD_CDDDBPOSIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbCONSTCOMP;
class CDDDbCONTENTCOMP;
class CDDDbEOSITERCOMP;
class CDDDbNAME;
class CDDDbNUMITERCOMP;
class CDDDbQUAL;
class CDDDbSIMPLEPROXYCOMP;
class CDDDbSTATICCOMP;
class CDDDbSTATUSDTCPROXYCOMP;

/**
 * @brief element POS
 *
 */
class VECTOR_CDD_API CDDDbPOSImpl
{
public:
    CDDDbPOSImpl();
    ~CDDDbPOSImpl();

    void load(const QDomElement &element);

    /** @attribute oid */
    QString m_oid;

    /** @attribute temploid */
    QString m_temploid;

    QString m_text;

    /** @element CONSTCOMP */
    QMap<QString, QSharedPointer<CDDDbCONSTCOMP>> m_elConstcomps;

    /** @element CONTENTCOMP */
    QMap<QString, QSharedPointer<CDDDbCONTENTCOMP>> m_elContentcomps;

    /** @element EOSITERCOMP */
    QSharedPointer<CDDDbEOSITERCOMP> m_elEositercomp;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_elName;

    /** @element NUMITERCOMP */
    QSharedPointer<CDDDbNUMITERCOMP> m_elNumitercomp;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_elQual;

    /** @element SIMPLEPROXYCOMP */
    QMap<QString, QSharedPointer<CDDDbSIMPLEPROXYCOMP>> m_elSimpleproxycomps;

    /** @element STATICCOMP */
    QSharedPointer<CDDDbSTATICCOMP> m_elStaticcomp;

    /** @element STATUSDTCPROXYCOMP */
    QSharedPointer<CDDDbSTATUSDTCPROXYCOMP> m_elStatusdtcproxycomp;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBPOSIMPL_H

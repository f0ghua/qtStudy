#ifndef VECTOR_CDD_CDDDBREQIMPL_H
#define VECTOR_CDD_CDDDBREQIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbCONSTCOMP;
class CDDDbCONTENTCOMP;
class CDDDbDOMAINDATAPROXYCOMP;
class CDDDbEOSITERCOMP;
class CDDDbGROUPOFDTCPROXYCOMP;
class CDDDbMUXCOMP;
class CDDDbNAME;
class CDDDbQUAL;
class CDDDbSIMPLEPROXYCOMP;
class CDDDbSTATICCOMP;
class CDDDbSTATUSDTCPROXYCOMP;

/**
 * @brief element REQ
 *
 */
class VECTOR_CDD_API CDDDbREQImpl
{
public:
    CDDDbREQImpl();
    ~CDDDbREQImpl();

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

    /** @element DOMAINDATAPROXYCOMP */
    QMap<QString, QSharedPointer<CDDDbDOMAINDATAPROXYCOMP>> m_elDomaindataproxycomps;

    /** @element EOSITERCOMP */
    QSharedPointer<CDDDbEOSITERCOMP> m_elEositercomp;

    /** @element GROUPOFDTCPROXYCOMP */
    QSharedPointer<CDDDbGROUPOFDTCPROXYCOMP> m_elGroupofdtcproxycomp;

    /** @element MUXCOMP */
    QSharedPointer<CDDDbMUXCOMP> m_elMuxcomp;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_elName;

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

#endif // VECTOR_CDD_CDDDBREQIMPL_H

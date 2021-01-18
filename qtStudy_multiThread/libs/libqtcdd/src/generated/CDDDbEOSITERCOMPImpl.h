#ifndef VECTOR_CDD_CDDDBEOSITERCOMPIMPL_H
#define VECTOR_CDD_CDDDBEOSITERCOMPIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbCONSTCOMP;
class CDDDbCONTENTCOMP;
class CDDDbDOMAINDATAPROXYCOMP;
class CDDDbMUXCOMP;
class CDDDbNAME;
class CDDDbQUAL;
class CDDDbSIMPLEPROXYCOMP;
class CDDDbSTATUSDTCPROXYCOMP;

/**
 * @brief element EOSITERCOMP
 *
 */
class VECTOR_CDD_API CDDDbEOSITERCOMPImpl
{
public:
    CDDDbEOSITERCOMPImpl();
    ~CDDDbEOSITERCOMPImpl();

    void load(const QDomElement &element);

    /** @attribute id */
    QString m_id;

    /** @attribute maxNumOfItems */
    QString m_maxNumOfItems;

    /** @attribute minNumOfItems */
    QString m_minNumOfItems;

    /** @attribute must */
    QString m_must;

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

    /** @element MUXCOMP */
    QSharedPointer<CDDDbMUXCOMP> m_elMuxcomp;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_elName;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_elQual;

    /** @element SIMPLEPROXYCOMP */
    QMap<QString, QSharedPointer<CDDDbSIMPLEPROXYCOMP>> m_elSimpleproxycomps;

    /** @element STATUSDTCPROXYCOMP */
    QSharedPointer<CDDDbSTATUSDTCPROXYCOMP> m_elStatusdtcproxycomp;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBEOSITERCOMPIMPL_H

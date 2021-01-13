#ifndef VECTOR_CDD_CDDDBEOSITERCOMP_H
#define VECTOR_CDD_CDDDBEOSITERCOMP_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbNAME;
class CDDDbQUAL;
class CDDDbSIMPLEPROXYCOMP;
class CDDDbSTATUSDTCPROXYCOMP;

/**
 * @brief element EOSITERCOMP
 *
 */
class VECTOR_CDD_API CDDDbEOSITERCOMP
{
public:
    CDDDbEOSITERCOMP();
    ~CDDDbEOSITERCOMP();

    void load(const QDomElement &element);

    /** @attribute id */
    QString m_id;

    /** @attribute minNumOfItems */
    QString m_minNumOfItems;

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

    /** @element SIMPLEPROXYCOMP */
    QMap<QString, QSharedPointer<CDDDbSIMPLEPROXYCOMP>> m_simpleproxycomps;

    /** @element STATUSDTCPROXYCOMP */
    QSharedPointer<CDDDbSTATUSDTCPROXYCOMP> m_statusdtcproxycomp;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBEOSITERCOMP_H

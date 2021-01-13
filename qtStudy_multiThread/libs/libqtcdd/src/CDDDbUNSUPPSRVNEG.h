#ifndef VECTOR_CDD_CDDDBUNSUPPSRVNEG_H
#define VECTOR_CDD_CDDDBUNSUPPSRVNEG_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbCONSTCOMP;
class CDDDbCONTENTCOMP;
class CDDDbNAME;
class CDDDbQUAL;
class CDDDbSTATICCOMP;

/**
 * @brief element UNSUPPSRVNEG
 *
 */
class VECTOR_CDD_API CDDDbUNSUPPSRVNEG
{
public:
    CDDDbUNSUPPSRVNEG();
    ~CDDDbUNSUPPSRVNEG();

    void load(const QDomElement &element);

    /** @attribute oid */
    QString m_oid;

    /** @attribute temploid */
    QString m_temploid;

    /** @element CONSTCOMP */
    QSharedPointer<CDDDbCONSTCOMP> m_constcomp;

    /** @element CONTENTCOMP */
    QSharedPointer<CDDDbCONTENTCOMP> m_contentcomp;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_name;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_qual;

    /** @element STATICCOMP */
    QSharedPointer<CDDDbSTATICCOMP> m_staticcomp;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBUNSUPPSRVNEG_H

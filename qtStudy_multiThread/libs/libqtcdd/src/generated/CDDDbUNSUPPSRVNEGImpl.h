#ifndef VECTOR_CDD_CDDDBUNSUPPSRVNEGIMPL_H
#define VECTOR_CDD_CDDDBUNSUPPSRVNEGIMPL_H

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
class VECTOR_CDD_API CDDDbUNSUPPSRVNEGImpl
{
public:
    CDDDbUNSUPPSRVNEGImpl();
    ~CDDDbUNSUPPSRVNEGImpl();

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

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_elName;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_elQual;

    /** @element STATICCOMP */
    QSharedPointer<CDDDbSTATICCOMP> m_elStaticcomp;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBUNSUPPSRVNEGIMPL_H

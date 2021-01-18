#ifndef VECTOR_CDD_CDDDBNUMITERCOMPIMPL_H
#define VECTOR_CDD_CDDDBNUMITERCOMPIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbNAME;
class CDDDbQUAL;
class CDDDbSIMPLEPROXYCOMP;

/**
 * @brief element NUMITERCOMP
 *
 */
class VECTOR_CDD_API CDDDbNUMITERCOMPImpl
{
public:
    CDDDbNUMITERCOMPImpl();
    ~CDDDbNUMITERCOMPImpl();

    void load(const QDomElement &element);

    /** @attribute id */
    QString m_id;

    /** @attribute must */
    QString m_must;

    /** @attribute oid */
    QString m_oid;

    /** @attribute selbm */
    QString m_selbm;

    /** @attribute selref */
    QString m_selref;

    /** @attribute temploid */
    QString m_temploid;

    QString m_text;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_elName;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_elQual;

    /** @element SIMPLEPROXYCOMP */
    QMap<QString, QSharedPointer<CDDDbSIMPLEPROXYCOMP>> m_elSimpleproxycomps;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBNUMITERCOMPIMPL_H

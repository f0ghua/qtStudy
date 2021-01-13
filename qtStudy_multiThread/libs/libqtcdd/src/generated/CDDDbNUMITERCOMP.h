#ifndef VECTOR_CDD_CDDDBNUMITERCOMP_H
#define VECTOR_CDD_CDDDBNUMITERCOMP_H

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
class VECTOR_CDD_API CDDDbNUMITERCOMP
{
public:
    CDDDbNUMITERCOMP();
    ~CDDDbNUMITERCOMP();

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

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_name;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_qual;

    /** @element SIMPLEPROXYCOMP */
    QSharedPointer<CDDDbSIMPLEPROXYCOMP> m_simpleproxycomp;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBNUMITERCOMP_H

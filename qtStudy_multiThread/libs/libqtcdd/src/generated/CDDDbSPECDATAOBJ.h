#ifndef VECTOR_CDD_CDDDBSPECDATAOBJ_H
#define VECTOR_CDD_CDDDBSPECDATAOBJ_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbNAME;
class CDDDbNEGRESCODEPROXIES;
class CDDDbQUAL;

/**
 * @brief element SPECDATAOBJ
 *
 */
class VECTOR_CDD_API CDDDbSPECDATAOBJ
{
public:
    CDDDbSPECDATAOBJ();
    ~CDDDbSPECDATAOBJ();

    void load(const QDomElement &element);

    /** @attribute oid */
    QString m_oid;

    /** @attribute temploid */
    QString m_temploid;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_name;

    /** @element NEGRESCODEPROXIES */
    QSharedPointer<CDDDbNEGRESCODEPROXIES> m_negrescodeproxies;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_qual;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSPECDATAOBJ_H

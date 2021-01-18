#ifndef VECTOR_CDD_CDDDBSPECDATAOBJIMPL_H
#define VECTOR_CDD_CDDDBSPECDATAOBJIMPL_H

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
class VECTOR_CDD_API CDDDbSPECDATAOBJImpl
{
public:
    CDDDbSPECDATAOBJImpl();
    ~CDDDbSPECDATAOBJImpl();

    void load(const QDomElement &element);

    /** @attribute oid */
    QString m_oid;

    /** @attribute temploid */
    QString m_temploid;

    QString m_text;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_elName;

    /** @element NEGRESCODEPROXIES */
    QSharedPointer<CDDDbNEGRESCODEPROXIES> m_elNegrescodeproxies;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_elQual;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSPECDATAOBJIMPL_H

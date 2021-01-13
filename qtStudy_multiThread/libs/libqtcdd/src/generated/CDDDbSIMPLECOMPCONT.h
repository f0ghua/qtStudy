#ifndef VECTOR_CDD_CDDDBSIMPLECOMPCONT_H
#define VECTOR_CDD_CDDDBSIMPLECOMPCONT_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbSPECDATAOBJ;

/**
 * @brief element SIMPLECOMPCONT
 *
 */
class VECTOR_CDD_API CDDDbSIMPLECOMPCONT
{
public:
    CDDDbSIMPLECOMPCONT();
    ~CDDDbSIMPLECOMPCONT();

    void load(const QDomElement &element);

    /** @attribute oid */
    QString m_oid;

    /** @attribute temploid */
    QString m_temploid;

    /** @element SPECDATAOBJ */
    QSharedPointer<CDDDbSPECDATAOBJ> m_specdataobj;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSIMPLECOMPCONT_H

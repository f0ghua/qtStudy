#ifndef VECTOR_CDD_CDDDBGAPDATAOBJ_H
#define VECTOR_CDD_CDDDBGAPDATAOBJ_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbNAME;
class CDDDbQUAL;

/**
 * @brief element GAPDATAOBJ
 *
 */
class VECTOR_CDD_API CDDDbGAPDATAOBJ
{
public:
    CDDDbGAPDATAOBJ();
    ~CDDDbGAPDATAOBJ();

    void load(const QDomElement &element);

    /** @attribute bl */
    QString m_bl;

    /** @attribute oid */
    QString m_oid;

    /** @attribute temploid */
    QString m_temploid;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_name;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_qual;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBGAPDATAOBJ_H

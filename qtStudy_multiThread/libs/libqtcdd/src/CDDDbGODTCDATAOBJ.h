#ifndef VECTOR_CDD_CDDDBGODTCDATAOBJ_H
#define VECTOR_CDD_CDDDBGODTCDATAOBJ_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbNAME;
class CDDDbQUAL;
class CDDDbTEXTTBL;

/**
 * @brief element GODTCDATAOBJ
 *
 */
class VECTOR_CDD_API CDDDbGODTCDATAOBJ
{
public:
    CDDDbGODTCDATAOBJ();
    ~CDDDbGODTCDATAOBJ();

    void load(const QDomElement &element);

    /** @attribute def */
    QString m_def;

    /** @attribute individualDtcs */
    QString m_individualDtcs;

    /** @attribute oid */
    QString m_oid;

    /** @attribute spec */
    QString m_spec;

    /** @attribute temploid */
    QString m_temploid;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_name;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_qual;

    /** @element TEXTTBL */
    QSharedPointer<CDDDbTEXTTBL> m_texttbl;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBGODTCDATAOBJ_H

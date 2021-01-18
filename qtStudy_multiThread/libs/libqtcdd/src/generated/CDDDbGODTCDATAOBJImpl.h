#ifndef VECTOR_CDD_CDDDBGODTCDATAOBJIMPL_H
#define VECTOR_CDD_CDDDBGODTCDATAOBJIMPL_H

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
class VECTOR_CDD_API CDDDbGODTCDATAOBJImpl
{
public:
    CDDDbGODTCDATAOBJImpl();
    ~CDDDbGODTCDATAOBJImpl();

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

    QString m_text;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_elName;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_elQual;

    /** @element TEXTTBL */
    QMap<QString, QSharedPointer<CDDDbTEXTTBL>> m_elTexttbls;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBGODTCDATAOBJIMPL_H

#ifndef VECTOR_CDD_CDDDBDATAOBJ_H
#define VECTOR_CDD_CDDDBDATAOBJ_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbNAME;
class CDDDbQUAL;

/**
 * @brief element DATAOBJ
 *
 */
class VECTOR_CDD_API CDDDbDATAOBJ
{
public:
    CDDDbDATAOBJ();
    ~CDDDbDATAOBJ();

    void load(const QDomElement &element);

    /** @attribute def */
    QString m_def;

    /** @attribute dtref */
    QString m_dtref;

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

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDATAOBJ_H

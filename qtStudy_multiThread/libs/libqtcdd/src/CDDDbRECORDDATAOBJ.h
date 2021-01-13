#ifndef VECTOR_CDD_CDDDBRECORDDATAOBJ_H
#define VECTOR_CDD_CDDDBRECORDDATAOBJ_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbNAME;
class CDDDbQUAL;
class CDDDbRECORDDT;

/**
 * @brief element RECORDDATAOBJ
 *
 */
class VECTOR_CDD_API CDDDbRECORDDATAOBJ
{
public:
    CDDDbRECORDDATAOBJ();
    ~CDDDbRECORDDATAOBJ();

    void load(const QDomElement &element);

    /** @attribute oid */
    QString m_oid;

    /** @attribute rtSpec */
    QString m_rtSpec;

    /** @attribute temploid */
    QString m_temploid;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_name;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_qual;

    /** @element RECORDDT */
    QSharedPointer<CDDDbRECORDDT> m_recorddt;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBRECORDDATAOBJ_H

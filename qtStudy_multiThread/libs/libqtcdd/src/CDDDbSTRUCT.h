#ifndef VECTOR_CDD_CDDDBSTRUCT_H
#define VECTOR_CDD_CDDDBSTRUCT_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbDATAOBJ;
class CDDDbGAPDATAOBJ;
class CDDDbNAME;
class CDDDbQUAL;

/**
 * @brief element STRUCT
 *
 */
class VECTOR_CDD_API CDDDbSTRUCT
{
public:
    CDDDbSTRUCT();
    ~CDDDbSTRUCT();

    void load(const QDomElement &element);

    /** @attribute dtref */
    QString m_dtref;

    /** @attribute oid */
    QString m_oid;

    /** @attribute spec */
    QString m_spec;

    /** @attribute temploid */
    QString m_temploid;

    /** @element DATAOBJ */
    QVector<QSharedPointer<CDDDbDATAOBJ>> m_dataobjs;

    /** @element GAPDATAOBJ */
    QVector<QSharedPointer<CDDDbGAPDATAOBJ>> m_gapdataobjs;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_name;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_qual;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSTRUCT_H

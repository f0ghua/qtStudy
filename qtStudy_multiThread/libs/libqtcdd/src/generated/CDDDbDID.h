#ifndef VECTOR_CDD_CDDDBDID_H
#define VECTOR_CDD_CDDDBDID_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbNAME;
class CDDDbQUAL;
class CDDDbSTRUCTURE;

/**
 * @brief element DID
 *
 */
class VECTOR_CDD_API CDDDbDID
{
public:
    CDDDbDID();
    ~CDDDbDID();

    void load(const QDomElement &element);

    /** @attribute id */
    QString m_id;

    /** @attribute n */
    QString m_n;

    /** @attribute oid */
    QString m_oid;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_name;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_qual;

    /** @element STRUCTURE */
    QSharedPointer<CDDDbSTRUCTURE> m_structure;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDID_H

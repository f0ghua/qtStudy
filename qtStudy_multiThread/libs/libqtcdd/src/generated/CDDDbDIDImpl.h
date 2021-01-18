#ifndef VECTOR_CDD_CDDDBDIDIMPL_H
#define VECTOR_CDD_CDDDBDIDIMPL_H

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
class VECTOR_CDD_API CDDDbDIDImpl
{
public:
    CDDDbDIDImpl();
    ~CDDDbDIDImpl();

    void load(const QDomElement &element);

    /** @attribute id */
    QString m_id;

    /** @attribute n */
    QString m_n;

    /** @attribute oid */
    QString m_oid;

    QString m_text;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_elName;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_elQual;

    /** @element STRUCTURE */
    QSharedPointer<CDDDbSTRUCTURE> m_elStructure;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDIDIMPL_H

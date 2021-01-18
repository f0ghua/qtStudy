#ifndef VECTOR_CDD_CDDDBCASEIMPL_H
#define VECTOR_CDD_CDDDBCASEIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbSTRUCTURE;

/**
 * @brief element CASE
 *
 */
class VECTOR_CDD_API CDDDbCASEImpl
{
public:
    CDDDbCASEImpl();
    ~CDDDbCASEImpl();

    void load(const QDomElement &element);

    /** @attribute e */
    QString m_e;

    /** @attribute oid */
    QString m_oid;

    /** @attribute s */
    QString m_s;

    /** @attribute temploid */
    QString m_temploid;

    QString m_text;

    /** @element STRUCTURE */
    QSharedPointer<CDDDbSTRUCTURE> m_elStructure;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBCASEIMPL_H

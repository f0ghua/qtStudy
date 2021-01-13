#ifndef VECTOR_CDD_CDDDBUNS_H
#define VECTOR_CDD_CDDDBUNS_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {


/**
 * @brief element UNS
 *
 */
class VECTOR_CDD_API CDDDbUNS
{
public:
    CDDDbUNS();
    ~CDDDbUNS();

    void load(const QDomElement &element);

    /** @attribute attrref */
    QString m_attrref;

    /** @attribute oid */
    QString m_oid;

    /** @attribute v */
    QString m_v;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBUNS_H

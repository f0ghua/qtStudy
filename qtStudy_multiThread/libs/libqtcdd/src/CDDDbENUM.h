#ifndef VECTOR_CDD_CDDDBENUM_H
#define VECTOR_CDD_CDDDBENUM_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {


/**
 * @brief element ENUM
 *
 */
class VECTOR_CDD_API CDDDbENUM
{
public:
    CDDDbENUM();
    ~CDDDbENUM();

    void load(const QDomElement &element);

    /** @attribute attrref */
    QString m_attrref;

    /** @attribute oid */
    QString m_oid;

    /** @attribute temploid */
    QString m_temploid;

    /** @attribute v */
    QString m_v;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBENUM_H

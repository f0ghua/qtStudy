#ifndef VECTOR_CDD_CDDDBENUMIMPL_H
#define VECTOR_CDD_CDDDBENUMIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {


/**
 * @brief element ENUM
 *
 */
class VECTOR_CDD_API CDDDbENUMImpl
{
public:
    CDDDbENUMImpl();
    ~CDDDbENUMImpl();

    void load(const QDomElement &element);

    /** @attribute attrref */
    QString m_attrref;

    /** @attribute oid */
    QString m_oid;

    /** @attribute temploid */
    QString m_temploid;

    /** @attribute v */
    QString m_v;

    QString m_text;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBENUMIMPL_H

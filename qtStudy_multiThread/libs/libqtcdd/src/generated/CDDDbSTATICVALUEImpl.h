#ifndef VECTOR_CDD_CDDDBSTATICVALUEIMPL_H
#define VECTOR_CDD_CDDDBSTATICVALUEIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {


/**
 * @brief element STATICVALUE
 *
 */
class VECTOR_CDD_API CDDDbSTATICVALUEImpl
{
public:
    CDDDbSTATICVALUEImpl();
    ~CDDDbSTATICVALUEImpl();

    void load(const QDomElement &element);

    /** @attribute oid */
    QString m_oid;

    /** @attribute shstaticref */
    QString m_shstaticref;

    /** @attribute temploid */
    QString m_temploid;

    /** @attribute v */
    QString m_v;

    QString m_text;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSTATICVALUEIMPL_H

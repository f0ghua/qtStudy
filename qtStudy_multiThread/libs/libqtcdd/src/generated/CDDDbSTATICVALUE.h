#ifndef VECTOR_CDD_CDDDBSTATICVALUE_H
#define VECTOR_CDD_CDDDBSTATICVALUE_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {


/**
 * @brief element STATICVALUE
 *
 */
class VECTOR_CDD_API CDDDbSTATICVALUE
{
public:
    CDDDbSTATICVALUE();
    ~CDDDbSTATICVALUE();

    void load(const QDomElement &element);

    /** @attribute oid */
    QString m_oid;

    /** @attribute shstaticref */
    QString m_shstaticref;

    /** @attribute temploid */
    QString m_temploid;

    /** @attribute v */
    QString m_v;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSTATICVALUE_H

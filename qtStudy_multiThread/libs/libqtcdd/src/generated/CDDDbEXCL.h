#ifndef VECTOR_CDD_CDDDBEXCL_H
#define VECTOR_CDD_CDDDBEXCL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {


/**
 * @brief element EXCL
 *
 */
class VECTOR_CDD_API CDDDbEXCL
{
public:
    CDDDbEXCL();
    ~CDDDbEXCL();

    void load(const QDomElement &element);

    /** @attribute e */
    QString m_e;

    /** @attribute inv */
    QString m_inv;

    /** @attribute s */
    QString m_s;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBEXCL_H

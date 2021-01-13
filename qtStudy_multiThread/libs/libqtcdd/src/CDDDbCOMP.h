#ifndef VECTOR_CDD_CDDDBCOMP_H
#define VECTOR_CDD_CDDDBCOMP_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {


/**
 * @brief element COMP
 *
 */
class VECTOR_CDD_API CDDDbCOMP
{
public:
    CDDDbCOMP();
    ~CDDDbCOMP();

    void load(const QDomElement &element);

    /** @attribute f */
    QString m_f;

    /** @attribute o */
    QString m_o;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBCOMP_H

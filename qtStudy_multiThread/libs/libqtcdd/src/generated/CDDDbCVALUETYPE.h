#ifndef VECTOR_CDD_CDDDBCVALUETYPE_H
#define VECTOR_CDD_CDDDBCVALUETYPE_H

#include "CDDDbCVALUETYPEImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element CVALUETYPE
 *
 */
class VECTOR_CDD_API CDDDbCVALUETYPE : public CDDDbCVALUETYPEImpl
{
public:
    CDDDbCVALUETYPE();
    ~CDDDbCVALUETYPE();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBCVALUETYPE_H

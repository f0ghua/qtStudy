#ifndef VECTOR_CDD_CDDDBPVALUETYPE_H
#define VECTOR_CDD_CDDDBPVALUETYPE_H

#include "CDDDbPVALUETYPEImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element PVALUETYPE
 *
 */
class VECTOR_CDD_API CDDDbPVALUETYPE : public CDDDbPVALUETYPEImpl
{
public:
    CDDDbPVALUETYPE();
    ~CDDDbPVALUETYPE();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBPVALUETYPE_H

#ifndef VECTOR_CDD_CDDDBQUAL_H
#define VECTOR_CDD_CDDDBQUAL_H

#include "CDDDbQUALImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element QUAL
 *
 */
class VECTOR_CDD_API CDDDbQUAL : public CDDDbQUALImpl
{
public:
    CDDDbQUAL();
    ~CDDDbQUAL();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBQUAL_H

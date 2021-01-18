#ifndef VECTOR_CDD_CDDDBHISTITEM_H
#define VECTOR_CDD_CDDDBHISTITEM_H

#include "CDDDbHISTITEMImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element HISTITEM
 *
 */
class VECTOR_CDD_API CDDDbHISTITEM : public CDDDbHISTITEMImpl
{
public:
    CDDDbHISTITEM();
    ~CDDDbHISTITEM();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBHISTITEM_H

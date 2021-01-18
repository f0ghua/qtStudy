#ifndef VECTOR_CDD_CDDDBHISTITEMS_H
#define VECTOR_CDD_CDDDBHISTITEMS_H

#include "CDDDbHISTITEMSImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element HISTITEMS
 *
 */
class VECTOR_CDD_API CDDDbHISTITEMS : public CDDDbHISTITEMSImpl
{
public:
    CDDDbHISTITEMS();
    ~CDDDbHISTITEMS();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBHISTITEMS_H

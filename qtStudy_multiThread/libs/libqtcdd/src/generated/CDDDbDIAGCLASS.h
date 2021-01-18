#ifndef VECTOR_CDD_CDDDBDIAGCLASS_H
#define VECTOR_CDD_CDDDBDIAGCLASS_H

#include "CDDDbDIAGCLASSImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element DIAGCLASS
 *
 */
class VECTOR_CDD_API CDDDbDIAGCLASS : public CDDDbDIAGCLASSImpl
{
public:
    CDDDbDIAGCLASS();
    ~CDDDbDIAGCLASS();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDIAGCLASS_H

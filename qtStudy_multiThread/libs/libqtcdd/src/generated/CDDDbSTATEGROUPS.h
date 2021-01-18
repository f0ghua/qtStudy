#ifndef VECTOR_CDD_CDDDBSTATEGROUPS_H
#define VECTOR_CDD_CDDDBSTATEGROUPS_H

#include "CDDDbSTATEGROUPSImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element STATEGROUPS
 *
 */
class VECTOR_CDD_API CDDDbSTATEGROUPS : public CDDDbSTATEGROUPSImpl
{
public:
    CDDDbSTATEGROUPS();
    ~CDDDbSTATEGROUPS();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSTATEGROUPS_H

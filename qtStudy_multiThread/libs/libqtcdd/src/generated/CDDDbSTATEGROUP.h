#ifndef VECTOR_CDD_CDDDBSTATEGROUP_H
#define VECTOR_CDD_CDDDBSTATEGROUP_H

#include "CDDDbSTATEGROUPImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element STATEGROUP
 *
 */
class VECTOR_CDD_API CDDDbSTATEGROUP : public CDDDbSTATEGROUPImpl
{
public:
    CDDDbSTATEGROUP();
    ~CDDDbSTATEGROUP();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSTATEGROUP_H

#ifndef VECTOR_CDD_CDDDBSTATE_H
#define VECTOR_CDD_CDDDBSTATE_H

#include "CDDDbSTATEImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element STATE
 *
 */
class VECTOR_CDD_API CDDDbSTATE : public CDDDbSTATEImpl
{
public:
    CDDDbSTATE();
    ~CDDDbSTATE();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSTATE_H

#ifndef VECTOR_CDD_CDDDBSTRUCTURE_H
#define VECTOR_CDD_CDDDBSTRUCTURE_H

#include "CDDDbSTRUCTUREImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element STRUCTURE
 *
 */
class VECTOR_CDD_API CDDDbSTRUCTURE : public CDDDbSTRUCTUREImpl
{
public:
    CDDDbSTRUCTURE();
    ~CDDDbSTRUCTURE();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSTRUCTURE_H

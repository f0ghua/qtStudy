#ifndef VECTOR_CDD_CDDDBSTRUCT_H
#define VECTOR_CDD_CDDDBSTRUCT_H

#include "CDDDbSTRUCTImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element STRUCT
 *
 */
class VECTOR_CDD_API CDDDbSTRUCT : public CDDDbSTRUCTImpl
{
public:
    CDDDbSTRUCT();
    ~CDDDbSTRUCT();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSTRUCT_H

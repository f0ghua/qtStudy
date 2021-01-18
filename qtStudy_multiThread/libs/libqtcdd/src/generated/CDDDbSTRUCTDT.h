#ifndef VECTOR_CDD_CDDDBSTRUCTDT_H
#define VECTOR_CDD_CDDDBSTRUCTDT_H

#include "CDDDbSTRUCTDTImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element STRUCTDT
 *
 */
class VECTOR_CDD_API CDDDbSTRUCTDT : public CDDDbSTRUCTDTImpl
{
public:
    CDDDbSTRUCTDT();
    ~CDDDbSTRUCTDT();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSTRUCTDT_H

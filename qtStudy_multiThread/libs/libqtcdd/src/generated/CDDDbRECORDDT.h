#ifndef VECTOR_CDD_CDDDBRECORDDT_H
#define VECTOR_CDD_CDDDBRECORDDT_H

#include "CDDDbRECORDDTImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element RECORDDT
 *
 */
class VECTOR_CDD_API CDDDbRECORDDT : public CDDDbRECORDDTImpl
{
public:
    CDDDbRECORDDT();
    ~CDDDbRECORDDT();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBRECORDDT_H

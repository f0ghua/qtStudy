#ifndef VECTOR_CDD_CDDDBDATATYPES_H
#define VECTOR_CDD_CDDDBDATATYPES_H

#include "CDDDbDATATYPESImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element DATATYPES
 *
 */
class VECTOR_CDD_API CDDDbDATATYPES : public CDDDbDATATYPESImpl
{
public:
    CDDDbDATATYPES();
    ~CDDDbDATATYPES();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDATATYPES_H

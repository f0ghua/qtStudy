#ifndef VECTOR_CDD_CDDDBRECORD_H
#define VECTOR_CDD_CDDDBRECORD_H

#include "CDDDbRECORDImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element RECORD
 *
 */
class VECTOR_CDD_API CDDDbRECORD : public CDDDbRECORDImpl
{
public:
    CDDDbRECORD();
    ~CDDDbRECORD();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBRECORD_H

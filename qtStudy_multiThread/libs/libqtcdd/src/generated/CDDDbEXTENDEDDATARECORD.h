#ifndef VECTOR_CDD_CDDDBEXTENDEDDATARECORD_H
#define VECTOR_CDD_CDDDBEXTENDEDDATARECORD_H

#include "CDDDbEXTENDEDDATARECORDImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element EXTENDEDDATARECORD
 *
 */
class VECTOR_CDD_API CDDDbEXTENDEDDATARECORD : public CDDDbEXTENDEDDATARECORDImpl
{
public:
    CDDDbEXTENDEDDATARECORD();
    ~CDDDbEXTENDEDDATARECORD();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBEXTENDEDDATARECORD_H

#ifndef VECTOR_CDD_CDDDBEXTENDEDDATARECORDS_H
#define VECTOR_CDD_CDDDBEXTENDEDDATARECORDS_H

#include "CDDDbEXTENDEDDATARECORDSImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element EXTENDEDDATARECORDS
 *
 */
class VECTOR_CDD_API CDDDbEXTENDEDDATARECORDS : public CDDDbEXTENDEDDATARECORDSImpl
{
public:
    CDDDbEXTENDEDDATARECORDS();
    ~CDDDbEXTENDEDDATARECORDS();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBEXTENDEDDATARECORDS_H

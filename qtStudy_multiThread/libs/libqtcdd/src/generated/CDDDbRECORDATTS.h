#ifndef VECTOR_CDD_CDDDBRECORDATTS_H
#define VECTOR_CDD_CDDDBRECORDATTS_H

#include "CDDDbRECORDATTSImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element RECORDATTS
 *
 */
class VECTOR_CDD_API CDDDbRECORDATTS : public CDDDbRECORDATTSImpl
{
public:
    CDDDbRECORDATTS();
    ~CDDDbRECORDATTS();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBRECORDATTS_H

#ifndef VECTOR_CDD_CDDDBJOBATTS_H
#define VECTOR_CDD_CDDDBJOBATTS_H

#include "CDDDbJOBATTSImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element JOBATTS
 *
 */
class VECTOR_CDD_API CDDDbJOBATTS : public CDDDbJOBATTSImpl
{
public:
    CDDDbJOBATTS();
    ~CDDDbJOBATTS();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBJOBATTS_H

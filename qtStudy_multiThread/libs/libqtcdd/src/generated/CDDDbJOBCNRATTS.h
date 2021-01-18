#ifndef VECTOR_CDD_CDDDBJOBCNRATTS_H
#define VECTOR_CDD_CDDDBJOBCNRATTS_H

#include "CDDDbJOBCNRATTSImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element JOBCNRATTS
 *
 */
class VECTOR_CDD_API CDDDbJOBCNRATTS : public CDDDbJOBCNRATTSImpl
{
public:
    CDDDbJOBCNRATTS();
    ~CDDDbJOBCNRATTS();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBJOBCNRATTS_H

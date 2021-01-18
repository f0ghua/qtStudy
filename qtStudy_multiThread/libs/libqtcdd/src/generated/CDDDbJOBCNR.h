#ifndef VECTOR_CDD_CDDDBJOBCNR_H
#define VECTOR_CDD_CDDDBJOBCNR_H

#include "CDDDbJOBCNRImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element JOBCNR
 *
 */
class VECTOR_CDD_API CDDDbJOBCNR : public CDDDbJOBCNRImpl
{
public:
    CDDDbJOBCNR();
    ~CDDDbJOBCNR();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBJOBCNR_H

#ifndef VECTOR_CDD_CDDDBAUTHORS_H
#define VECTOR_CDD_CDDDBAUTHORS_H

#include "CDDDbAUTHORSImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element AUTHORS
 *
 */
class VECTOR_CDD_API CDDDbAUTHORS : public CDDDbAUTHORSImpl
{
public:
    CDDDbAUTHORS();
    ~CDDDbAUTHORS();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBAUTHORS_H

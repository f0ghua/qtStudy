#ifndef VECTOR_CDD_CDDDBLINCOMP_H
#define VECTOR_CDD_CDDDBLINCOMP_H

#include "CDDDbLINCOMPImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element LINCOMP
 *
 */
class VECTOR_CDD_API CDDDbLINCOMP : public CDDDbLINCOMPImpl
{
public:
    CDDDbLINCOMP();
    ~CDDDbLINCOMP();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBLINCOMP_H

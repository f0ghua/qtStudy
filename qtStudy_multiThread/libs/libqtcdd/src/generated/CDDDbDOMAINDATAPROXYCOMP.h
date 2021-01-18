#ifndef VECTOR_CDD_CDDDBDOMAINDATAPROXYCOMP_H
#define VECTOR_CDD_CDDDBDOMAINDATAPROXYCOMP_H

#include "CDDDbDOMAINDATAPROXYCOMPImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element DOMAINDATAPROXYCOMP
 *
 */
class VECTOR_CDD_API CDDDbDOMAINDATAPROXYCOMP : public CDDDbDOMAINDATAPROXYCOMPImpl
{
public:
    CDDDbDOMAINDATAPROXYCOMP();
    ~CDDDbDOMAINDATAPROXYCOMP();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDOMAINDATAPROXYCOMP_H

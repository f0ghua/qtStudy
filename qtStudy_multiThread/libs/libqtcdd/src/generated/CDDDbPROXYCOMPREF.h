#ifndef VECTOR_CDD_CDDDBPROXYCOMPREF_H
#define VECTOR_CDD_CDDDBPROXYCOMPREF_H

#include "CDDDbPROXYCOMPREFImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element PROXYCOMPREF
 *
 */
class VECTOR_CDD_API CDDDbPROXYCOMPREF : public CDDDbPROXYCOMPREFImpl
{
public:
    CDDDbPROXYCOMPREF();
    ~CDDDbPROXYCOMPREF();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBPROXYCOMPREF_H

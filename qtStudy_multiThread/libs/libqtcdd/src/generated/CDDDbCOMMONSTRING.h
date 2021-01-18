#ifndef VECTOR_CDD_CDDDBCOMMONSTRING_H
#define VECTOR_CDD_CDDDBCOMMONSTRING_H

#include "CDDDbCOMMONSTRINGImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element COMMONSTRING
 *
 */
class VECTOR_CDD_API CDDDbCOMMONSTRING : public CDDDbCOMMONSTRINGImpl
{
public:
    CDDDbCOMMONSTRING();
    ~CDDDbCOMMONSTRING();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBCOMMONSTRING_H

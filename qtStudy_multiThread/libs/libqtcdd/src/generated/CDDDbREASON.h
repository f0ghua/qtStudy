#ifndef VECTOR_CDD_CDDDBREASON_H
#define VECTOR_CDD_CDDDBREASON_H

#include "CDDDbREASONImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element REASON
 *
 */
class VECTOR_CDD_API CDDDbREASON : public CDDDbREASONImpl
{
public:
    CDDDbREASON();
    ~CDDDbREASON();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBREASON_H

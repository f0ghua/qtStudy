#ifndef VECTOR_CDD_CDDDBAUTHOR_H
#define VECTOR_CDD_CDDDBAUTHOR_H

#include "CDDDbAUTHORImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element AUTHOR
 *
 */
class VECTOR_CDD_API CDDDbAUTHOR : public CDDDbAUTHORImpl
{
public:
    CDDDbAUTHOR();
    ~CDDDbAUTHOR();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBAUTHOR_H

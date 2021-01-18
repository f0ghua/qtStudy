#ifndef VECTOR_CDD_CDDDBTEXTMAP_H
#define VECTOR_CDD_CDDDBTEXTMAP_H

#include "CDDDbTEXTMAPImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element TEXTMAP
 *
 */
class VECTOR_CDD_API CDDDbTEXTMAP : public CDDDbTEXTMAPImpl
{
public:
    CDDDbTEXTMAP();
    ~CDDDbTEXTMAP();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBTEXTMAP_H

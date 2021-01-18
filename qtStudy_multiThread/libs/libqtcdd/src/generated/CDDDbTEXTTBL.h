#ifndef VECTOR_CDD_CDDDBTEXTTBL_H
#define VECTOR_CDD_CDDDBTEXTTBL_H

#include "CDDDbTEXTTBLImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element TEXTTBL
 *
 */
class VECTOR_CDD_API CDDDbTEXTTBL : public CDDDbTEXTTBLImpl
{
public:
    CDDDbTEXTTBL();
    ~CDDDbTEXTTBL();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBTEXTTBL_H

#ifndef VECTOR_CDD_CDDDBLABEL_H
#define VECTOR_CDD_CDDDBLABEL_H

#include "CDDDbLABELImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element LABEL
 *
 */
class VECTOR_CDD_API CDDDbLABEL : public CDDDbLABELImpl
{
public:
    CDDDbLABEL();
    ~CDDDbLABEL();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBLABEL_H

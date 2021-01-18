#ifndef VECTOR_CDD_CDDDBIDENT_H
#define VECTOR_CDD_CDDDBIDENT_H

#include "CDDDbIDENTImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element IDENT
 *
 */
class VECTOR_CDD_API CDDDbIDENT : public CDDDbIDENTImpl
{
public:
    CDDDbIDENT();
    ~CDDDbIDENT();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBIDENT_H

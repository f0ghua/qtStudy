#ifndef VECTOR_CDD_CDDDBCOMPANY_H
#define VECTOR_CDD_CDDDBCOMPANY_H

#include "CDDDbCOMPANYImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element COMPANY
 *
 */
class VECTOR_CDD_API CDDDbCOMPANY : public CDDDbCOMPANYImpl
{
public:
    CDDDbCOMPANY();
    ~CDDDbCOMPANY();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBCOMPANY_H

#ifndef VECTOR_CDD_CDDDBSTATICCOMPREF_H
#define VECTOR_CDD_CDDDBSTATICCOMPREF_H

#include "CDDDbSTATICCOMPREFImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element STATICCOMPREF
 *
 */
class VECTOR_CDD_API CDDDbSTATICCOMPREF : public CDDDbSTATICCOMPREFImpl
{
public:
    CDDDbSTATICCOMPREF();
    ~CDDDbSTATICCOMPREF();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSTATICCOMPREF_H

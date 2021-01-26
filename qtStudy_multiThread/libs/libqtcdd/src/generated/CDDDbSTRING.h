#ifndef VECTOR_CDD_CDDDBSTRING_H
#define VECTOR_CDD_CDDDBSTRING_H

#include "CDDDbNAME.h"

namespace vector {
namespace cdd {

/**
 * @brief element STRING
 *
 */
class VECTOR_CDD_API CDDDbSTRING : public CDDDbNAME
{
public:
    CDDDbSTRING();
    ~CDDDbSTRING();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSTRING_H

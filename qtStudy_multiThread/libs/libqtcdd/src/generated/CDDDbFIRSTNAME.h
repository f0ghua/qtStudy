#ifndef VECTOR_CDD_CDDDBFIRSTNAME_H
#define VECTOR_CDD_CDDDBFIRSTNAME_H

#include "CDDDbFIRSTNAMEImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element FIRSTNAME
 *
 */
class VECTOR_CDD_API CDDDbFIRSTNAME : public CDDDbFIRSTNAMEImpl
{
public:
    CDDDbFIRSTNAME();
    ~CDDDbFIRSTNAME();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBFIRSTNAME_H

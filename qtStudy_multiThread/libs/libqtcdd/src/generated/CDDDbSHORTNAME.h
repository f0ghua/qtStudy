#ifndef VECTOR_CDD_CDDDBSHORTNAME_H
#define VECTOR_CDD_CDDDBSHORTNAME_H

#include "CDDDbSHORTNAMEImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element SHORTNAME
 *
 */
class VECTOR_CDD_API CDDDbSHORTNAME : public CDDDbSHORTNAMEImpl
{
public:
    CDDDbSHORTNAME();
    ~CDDDbSHORTNAME();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSHORTNAME_H

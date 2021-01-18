#ifndef VECTOR_CDD_CDDDBADDINFO_H
#define VECTOR_CDD_CDDDBADDINFO_H

#include "CDDDbADDINFOImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element ADDINFO
 *
 */
class VECTOR_CDD_API CDDDbADDINFO : public CDDDbADDINFOImpl
{
public:
    CDDDbADDINFO();
    ~CDDDbADDINFO();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBADDINFO_H

#ifndef VECTOR_CDD_CDDDBPARA_H
#define VECTOR_CDD_CDDDBPARA_H

#include "CDDDbPARAImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element PARA
 *
 */
class VECTOR_CDD_API CDDDbPARA : public CDDDbPARAImpl
{
public:
    CDDDbPARA();
    ~CDDDbPARA();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBPARA_H

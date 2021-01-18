#ifndef VECTOR_CDD_CDDDBSPECOWNER_H
#define VECTOR_CDD_CDDDBSPECOWNER_H

#include "CDDDbSPECOWNERImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element SPECOWNER
 *
 */
class VECTOR_CDD_API CDDDbSPECOWNER : public CDDDbSPECOWNERImpl
{
public:
    CDDDbSPECOWNER();
    ~CDDDbSPECOWNER();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSPECOWNER_H

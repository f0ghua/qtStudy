#ifndef VECTOR_CDD_CDDDBSGNDEF_H
#define VECTOR_CDD_CDDDBSGNDEF_H

#include "CDDDbSGNDEFImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element SGNDEF
 *
 */
class VECTOR_CDD_API CDDDbSGNDEF : public CDDDbSGNDEFImpl
{
public:
    CDDDbSGNDEF();
    ~CDDDbSGNDEF();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSGNDEF_H

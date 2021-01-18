#ifndef VECTOR_CDD_CDDDBDIDDATAREF_H
#define VECTOR_CDD_CDDDBDIDDATAREF_H

#include "CDDDbDIDDATAREFImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element DIDDATAREF
 *
 */
class VECTOR_CDD_API CDDDbDIDDATAREF : public CDDDbDIDDATAREFImpl
{
public:
    CDDDbDIDDATAREF();
    ~CDDDbDIDDATAREF();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDIDDATAREF_H

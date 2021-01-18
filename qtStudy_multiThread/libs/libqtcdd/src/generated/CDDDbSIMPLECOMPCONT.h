#ifndef VECTOR_CDD_CDDDBSIMPLECOMPCONT_H
#define VECTOR_CDD_CDDDBSIMPLECOMPCONT_H

#include "CDDDbSIMPLECOMPCONTImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element SIMPLECOMPCONT
 *
 */
class VECTOR_CDD_API CDDDbSIMPLECOMPCONT : public CDDDbSIMPLECOMPCONTImpl
{
public:
    CDDDbSIMPLECOMPCONT();
    ~CDDDbSIMPLECOMPCONT();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSIMPLECOMPCONT_H

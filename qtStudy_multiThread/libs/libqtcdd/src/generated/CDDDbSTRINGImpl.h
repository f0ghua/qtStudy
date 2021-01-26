#ifndef VECTOR_CDD_CDDDBSTRINGIMPL_H
#define VECTOR_CDD_CDDDBSTRINGIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"
#include "CDDDbNAMEImpl.h"

namespace vector {
namespace cdd {

class CDDDbTUV;

/**
 * @brief element STRING
 *
 */
class VECTOR_CDD_API CDDDbSTRINGImpl : public CDDDbNAMEImpl
{
public:
    CDDDbSTRINGImpl();
    ~CDDDbSTRINGImpl();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSTRINGIMPL_H

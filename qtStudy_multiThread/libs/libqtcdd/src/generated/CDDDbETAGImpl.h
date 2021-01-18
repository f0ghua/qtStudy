#ifndef VECTOR_CDD_CDDDBETAGIMPL_H
#define VECTOR_CDD_CDDDBETAGIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"
#include "CDDDbNAMEImpl.h"

namespace vector {
namespace cdd {

class CDDDbTUV;

/**
 * @brief element ETAG
 *
 */
class VECTOR_CDD_API CDDDbETAGImpl : public CDDDbNAMEImpl
{
public:
    CDDDbETAGImpl();
    ~CDDDbETAGImpl();

    void load(const QDomElement &element);

    /** @attribute v */
    QString m_v;
};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBETAGIMPL_H

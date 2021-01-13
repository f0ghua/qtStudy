#ifndef VECTOR_CDD_CDDDBNAME_H
#define VECTOR_CDD_CDDDBNAME_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbTUV;

/**
 * @brief element NAME
 *
 */
class VECTOR_CDD_API CDDDbNAME
{
public:
    CDDDbNAME();
    ~CDDDbNAME();

    void load(const QDomElement &element);

    /** @element TUV */
    QSharedPointer<CDDDbTUV> m_tuv;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBNAME_H

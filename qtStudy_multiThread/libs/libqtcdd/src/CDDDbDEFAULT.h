#ifndef VECTOR_CDD_CDDDBDEFAULT_H
#define VECTOR_CDD_CDDDBDEFAULT_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbTUV;

/**
 * @brief element DEFAULT
 *
 */
class VECTOR_CDD_API CDDDbDEFAULT
{
public:
    CDDDbDEFAULT();
    ~CDDDbDEFAULT();

    void load(const QDomElement &element);

    /** @element TUV */
    QSharedPointer<CDDDbTUV> m_tuv;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDEFAULT_H

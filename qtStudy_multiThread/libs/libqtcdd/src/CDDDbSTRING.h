#ifndef VECTOR_CDD_CDDDBSTRING_H
#define VECTOR_CDD_CDDDBSTRING_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbTUV;

/**
 * @brief element STRING
 *
 */
class VECTOR_CDD_API CDDDbSTRING
{
public:
    CDDDbSTRING();
    ~CDDDbSTRING();

    void load(const QDomElement &element);

    /** @element TUV */
    QSharedPointer<CDDDbTUV> m_tuv;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSTRING_H

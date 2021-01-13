#ifndef VECTOR_CDD_CDDDBETAG_H
#define VECTOR_CDD_CDDDBETAG_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbTUV;

/**
 * @brief element ETAG
 *
 */
class VECTOR_CDD_API CDDDbETAG
{
public:
    CDDDbETAG();
    ~CDDDbETAG();

    void load(const QDomElement &element);

    /** @attribute v */
    QString m_v;

    /** @element TUV */
    QSharedPointer<CDDDbTUV> m_tuv;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBETAG_H

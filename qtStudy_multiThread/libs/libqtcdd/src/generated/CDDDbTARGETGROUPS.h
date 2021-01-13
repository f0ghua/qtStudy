#ifndef VECTOR_CDD_CDDDBTARGETGROUPS_H
#define VECTOR_CDD_CDDDBTARGETGROUPS_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbTARGETGROUP;

/**
 * @brief element TARGETGROUPS
 *
 */
class VECTOR_CDD_API CDDDbTARGETGROUPS
{
public:
    CDDDbTARGETGROUPS();
    ~CDDDbTARGETGROUPS();

    void load(const QDomElement &element);

    /** @element TARGETGROUP */
    QVector<QSharedPointer<CDDDbTARGETGROUP>> m_targetgroups;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBTARGETGROUPS_H

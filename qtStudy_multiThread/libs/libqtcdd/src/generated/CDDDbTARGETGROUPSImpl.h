#ifndef VECTOR_CDD_CDDDBTARGETGROUPSIMPL_H
#define VECTOR_CDD_CDDDBTARGETGROUPSIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbTARGETGROUP;

/**
 * @brief element TARGETGROUPS
 *
 */
class VECTOR_CDD_API CDDDbTARGETGROUPSImpl
{
public:
    CDDDbTARGETGROUPSImpl();
    ~CDDDbTARGETGROUPSImpl();

    void load(const QDomElement &element);

    QString m_text;

    /** @element TARGETGROUP */
    QVector<QSharedPointer<CDDDbTARGETGROUP>> m_elTargetgroups;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBTARGETGROUPSIMPL_H

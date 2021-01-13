#ifndef VECTOR_CDD_CDDDBSTATEGROUPS_H
#define VECTOR_CDD_CDDDBSTATEGROUPS_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbSTATEGROUP;

/**
 * @brief element STATEGROUPS
 *
 */
class VECTOR_CDD_API CDDDbSTATEGROUPS
{
public:
    CDDDbSTATEGROUPS();
    ~CDDDbSTATEGROUPS();

    void load(const QDomElement &element);

    /** @element STATEGROUP */
    QSharedPointer<CDDDbSTATEGROUP> m_stategroup;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSTATEGROUPS_H

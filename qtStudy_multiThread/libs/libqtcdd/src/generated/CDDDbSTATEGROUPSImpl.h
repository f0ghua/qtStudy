#ifndef VECTOR_CDD_CDDDBSTATEGROUPSIMPL_H
#define VECTOR_CDD_CDDDBSTATEGROUPSIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbSTATEGROUP;

/**
 * @brief element STATEGROUPS
 *
 */
class VECTOR_CDD_API CDDDbSTATEGROUPSImpl
{
public:
    CDDDbSTATEGROUPSImpl();
    ~CDDDbSTATEGROUPSImpl();

    void load(const QDomElement &element);

    QString m_text;

    /** @element STATEGROUP */
    QVector<QSharedPointer<CDDDbSTATEGROUP>> m_elStategroups;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSTATEGROUPSIMPL_H

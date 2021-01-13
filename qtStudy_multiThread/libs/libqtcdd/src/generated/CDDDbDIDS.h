#ifndef VECTOR_CDD_CDDDBDIDS_H
#define VECTOR_CDD_CDDDBDIDS_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbDID;

/**
 * @brief element DIDS
 *
 */
class VECTOR_CDD_API CDDDbDIDS
{
public:
    CDDDbDIDS();
    ~CDDDbDIDS();

    void load(const QDomElement &element);

    /** @element DID */
    QMap<QString, QSharedPointer<CDDDbDID>> m_dids;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDIDS_H

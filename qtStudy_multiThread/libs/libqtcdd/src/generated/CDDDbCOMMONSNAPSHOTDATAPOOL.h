#ifndef VECTOR_CDD_CDDDBCOMMONSNAPSHOTDATAPOOL_H
#define VECTOR_CDD_CDDDBCOMMONSNAPSHOTDATAPOOL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbDIDCOMMONSNAPSHOTDATA;

/**
 * @brief element COMMONSNAPSHOTDATAPOOL
 *
 */
class VECTOR_CDD_API CDDDbCOMMONSNAPSHOTDATAPOOL
{
public:
    CDDDbCOMMONSNAPSHOTDATAPOOL();
    ~CDDDbCOMMONSNAPSHOTDATAPOOL();

    void load(const QDomElement &element);

    /** @element DIDCOMMONSNAPSHOTDATA */
    QSharedPointer<CDDDbDIDCOMMONSNAPSHOTDATA> m_didcommonsnapshotdata;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBCOMMONSNAPSHOTDATAPOOL_H

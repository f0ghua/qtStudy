#ifndef VECTOR_CDD_CDDDBCOMMONSNAPSHOTDATAPOOLIMPL_H
#define VECTOR_CDD_CDDDBCOMMONSNAPSHOTDATAPOOLIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbDIDCOMMONSNAPSHOTDATA;

/**
 * @brief element COMMONSNAPSHOTDATAPOOL
 *
 */
class VECTOR_CDD_API CDDDbCOMMONSNAPSHOTDATAPOOLImpl
{
public:
    CDDDbCOMMONSNAPSHOTDATAPOOLImpl();
    ~CDDDbCOMMONSNAPSHOTDATAPOOLImpl();

    void load(const QDomElement &element);

    QString m_text;

    /** @element DIDCOMMONSNAPSHOTDATA */
    QSharedPointer<CDDDbDIDCOMMONSNAPSHOTDATA> m_elDidcommonsnapshotdata;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBCOMMONSNAPSHOTDATAPOOLIMPL_H

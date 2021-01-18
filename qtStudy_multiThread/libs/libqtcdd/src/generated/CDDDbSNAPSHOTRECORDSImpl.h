#ifndef VECTOR_CDD_CDDDBSNAPSHOTRECORDSIMPL_H
#define VECTOR_CDD_CDDDBSNAPSHOTRECORDSIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbSPECIFICSNAPSHOTRECORD;

/**
 * @brief element SNAPSHOTRECORDS
 *
 */
class VECTOR_CDD_API CDDDbSNAPSHOTRECORDSImpl
{
public:
    CDDDbSNAPSHOTRECORDSImpl();
    ~CDDDbSNAPSHOTRECORDSImpl();

    void load(const QDomElement &element);

    QString m_text;

    /** @element SPECIFICSNAPSHOTRECORD */
    QSharedPointer<CDDDbSPECIFICSNAPSHOTRECORD> m_elSpecificsnapshotrecord;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSNAPSHOTRECORDSIMPL_H

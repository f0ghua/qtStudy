#ifndef VECTOR_CDD_CDDDBSNAPSHOTRECORDS_H
#define VECTOR_CDD_CDDDBSNAPSHOTRECORDS_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbSPECIFICSNAPSHOTRECORD;

/**
 * @brief element SNAPSHOTRECORDS
 *
 */
class VECTOR_CDD_API CDDDbSNAPSHOTRECORDS
{
public:
    CDDDbSNAPSHOTRECORDS();
    ~CDDDbSNAPSHOTRECORDS();

    void load(const QDomElement &element);

    /** @element SPECIFICSNAPSHOTRECORD */
    QSharedPointer<CDDDbSPECIFICSNAPSHOTRECORD> m_specificsnapshotrecord;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSNAPSHOTRECORDS_H

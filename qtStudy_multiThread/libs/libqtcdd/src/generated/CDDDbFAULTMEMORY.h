#ifndef VECTOR_CDD_CDDDBFAULTMEMORY_H
#define VECTOR_CDD_CDDDBFAULTMEMORY_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbCOMMONSNAPSHOTDATAPOOL;
class CDDDbEXTENDEDDATARECORDS;
class CDDDbSNAPSHOTRECORDS;

/**
 * @brief element FAULTMEMORY
 *
 */
class VECTOR_CDD_API CDDDbFAULTMEMORY
{
public:
    CDDDbFAULTMEMORY();
    ~CDDDbFAULTMEMORY();

    void load(const QDomElement &element);

    /** @attribute dnDtRef */
    QString m_dnDtRef;

    /** @attribute forceDidSnapshotData */
    QString m_forceDidSnapshotData;

    /** @attribute forceSameSnapshotData */
    QString m_forceSameSnapshotData;

    /** @attribute mayBeAddDelEdr */
    QString m_mayBeAddDelEdr;

    /** @attribute mayBeAddDelSr */
    QString m_mayBeAddDelSr;

    /** @attribute supportDtcSpecificData */
    QString m_supportDtcSpecificData;

    /** @attribute supportEdrForDtc */
    QString m_supportEdrForDtc;

    /** @element COMMONSNAPSHOTDATAPOOL */
    QSharedPointer<CDDDbCOMMONSNAPSHOTDATAPOOL> m_commonsnapshotdatapool;

    /** @element EXTENDEDDATARECORDS */
    QSharedPointer<CDDDbEXTENDEDDATARECORDS> m_extendeddatarecords;

    /** @element SNAPSHOTRECORDS */
    QSharedPointer<CDDDbSNAPSHOTRECORDS> m_snapshotrecords;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBFAULTMEMORY_H

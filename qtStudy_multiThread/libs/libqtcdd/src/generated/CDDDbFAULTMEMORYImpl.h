#ifndef VECTOR_CDD_CDDDBFAULTMEMORYIMPL_H
#define VECTOR_CDD_CDDDBFAULTMEMORYIMPL_H

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
class VECTOR_CDD_API CDDDbFAULTMEMORYImpl
{
public:
    CDDDbFAULTMEMORYImpl();
    ~CDDDbFAULTMEMORYImpl();

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

    QString m_text;

    /** @element COMMONSNAPSHOTDATAPOOL */
    QSharedPointer<CDDDbCOMMONSNAPSHOTDATAPOOL> m_elCommonsnapshotdatapool;

    /** @element EXTENDEDDATARECORDS */
    QSharedPointer<CDDDbEXTENDEDDATARECORDS> m_elExtendeddatarecords;

    /** @element SNAPSHOTRECORDS */
    QSharedPointer<CDDDbSNAPSHOTRECORDS> m_elSnapshotrecords;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBFAULTMEMORYIMPL_H

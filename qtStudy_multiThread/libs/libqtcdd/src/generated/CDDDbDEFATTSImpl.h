#ifndef VECTOR_CDD_CDDDBDEFATTSIMPL_H
#define VECTOR_CDD_CDDDBDEFATTSIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbDATAOBJATTS;
class CDDDbDATATYPEATTS;
class CDDDbDCLSRVTMPLATTS;
class CDDDbDCLTMPLATTS;
class CDDDbDIAGCLASSATTS;
class CDDDbDIAGINSTATTS;
class CDDDbDIDATTS;
class CDDDbECUATTS;
class CDDDbJOBATTS;
class CDDDbJOBCNRATTS;
class CDDDbRECORDATTS;
class CDDDbSERVICEATTS;
class CDDDbSHPROXYATTS;
class CDDDbSTATEGROUPATTS;
class CDDDbVARATTS;

/**
 * @brief element DEFATTS
 *
 */
class VECTOR_CDD_API CDDDbDEFATTSImpl
{
public:
    CDDDbDEFATTSImpl();
    ~CDDDbDEFATTSImpl();

    void load(const QDomElement &element);

    QString m_text;

    /** @element DATAOBJATTS */
    QSharedPointer<CDDDbDATAOBJATTS> m_elDataobjatts;

    /** @element DATATYPEATTS */
    QSharedPointer<CDDDbDATATYPEATTS> m_elDatatypeatts;

    /** @element DCLSRVTMPLATTS */
    QSharedPointer<CDDDbDCLSRVTMPLATTS> m_elDclsrvtmplatts;

    /** @element DCLTMPLATTS */
    QSharedPointer<CDDDbDCLTMPLATTS> m_elDcltmplatts;

    /** @element DIAGCLASSATTS */
    QSharedPointer<CDDDbDIAGCLASSATTS> m_elDiagclassatts;

    /** @element DIAGINSTATTS */
    QSharedPointer<CDDDbDIAGINSTATTS> m_elDiaginstatts;

    /** @element DIDATTS */
    QSharedPointer<CDDDbDIDATTS> m_elDidatts;

    /** @element ECUATTS */
    QSharedPointer<CDDDbECUATTS> m_elEcuatts;

    /** @element JOBATTS */
    QSharedPointer<CDDDbJOBATTS> m_elJobatts;

    /** @element JOBCNRATTS */
    QSharedPointer<CDDDbJOBCNRATTS> m_elJobcnratts;

    /** @element RECORDATTS */
    QSharedPointer<CDDDbRECORDATTS> m_elRecordatts;

    /** @element SERVICEATTS */
    QSharedPointer<CDDDbSERVICEATTS> m_elServiceatts;

    /** @element SHPROXYATTS */
    QSharedPointer<CDDDbSHPROXYATTS> m_elShproxyatts;

    /** @element STATEGROUPATTS */
    QSharedPointer<CDDDbSTATEGROUPATTS> m_elStategroupatts;

    /** @element VARATTS */
    QSharedPointer<CDDDbVARATTS> m_elVaratts;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDEFATTSIMPL_H

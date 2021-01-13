#ifndef VECTOR_CDD_CDDDBDEFATTS_H
#define VECTOR_CDD_CDDDBDEFATTS_H

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
class VECTOR_CDD_API CDDDbDEFATTS
{
public:
    CDDDbDEFATTS();
    ~CDDDbDEFATTS();

    void load(const QDomElement &element);

    /** @element DATAOBJATTS */
    QSharedPointer<CDDDbDATAOBJATTS> m_dataobjatts;

    /** @element DATATYPEATTS */
    QSharedPointer<CDDDbDATATYPEATTS> m_datatypeatts;

    /** @element DCLSRVTMPLATTS */
    QSharedPointer<CDDDbDCLSRVTMPLATTS> m_dclsrvtmplatts;

    /** @element DCLTMPLATTS */
    QSharedPointer<CDDDbDCLTMPLATTS> m_dcltmplatts;

    /** @element DIAGCLASSATTS */
    QSharedPointer<CDDDbDIAGCLASSATTS> m_diagclassatts;

    /** @element DIAGINSTATTS */
    QSharedPointer<CDDDbDIAGINSTATTS> m_diaginstatts;

    /** @element DIDATTS */
    QSharedPointer<CDDDbDIDATTS> m_didatts;

    /** @element ECUATTS */
    QSharedPointer<CDDDbECUATTS> m_ecuatts;

    /** @element JOBATTS */
    QSharedPointer<CDDDbJOBATTS> m_jobatts;

    /** @element JOBCNRATTS */
    QSharedPointer<CDDDbJOBCNRATTS> m_jobcnratts;

    /** @element RECORDATTS */
    QSharedPointer<CDDDbRECORDATTS> m_recordatts;

    /** @element SERVICEATTS */
    QSharedPointer<CDDDbSERVICEATTS> m_serviceatts;

    /** @element SHPROXYATTS */
    QSharedPointer<CDDDbSHPROXYATTS> m_shproxyatts;

    /** @element STATEGROUPATTS */
    QSharedPointer<CDDDbSTATEGROUPATTS> m_stategroupatts;

    /** @element VARATTS */
    QSharedPointer<CDDDbVARATTS> m_varatts;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDEFATTS_H

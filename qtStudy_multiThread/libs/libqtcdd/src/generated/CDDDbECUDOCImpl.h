#ifndef VECTOR_CDD_CDDDBECUDOCIMPL_H
#define VECTOR_CDD_CDDDBECUDOCIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbATTRCATS;
class CDDDbAUTHORS;
class CDDDbDATATYPES;
class CDDDbDCLTMPLS;
class CDDDbDEFATTS;
class CDDDbDESC;
class CDDDbDIDS;
class CDDDbDOCTMPL;
class CDDDbDTCSTATUSMASK;
class CDDDbDTID;
class CDDDbECU;
class CDDDbHISTITEMS;
class CDDDbNEGRESCODES;
class CDDDbPROTOCOLSERVICES;
class CDDDbPROTOCOLSTANDARD;
class CDDDbQUALGENOPTIONS;
class CDDDbRECORDDTPOOL;
class CDDDbRECORDTMPLS;
class CDDDbSPECOWNER;
class CDDDbSTATEGROUPS;
class CDDDbTARGETGROUPS;
class CDDDbUNSUPPSRVNEG;
class CDDDbVCKMGR;

/**
 * @brief element ECUDOC
 *
 */
class VECTOR_CDD_API CDDDbECUDOCImpl
{
public:
    CDDDbECUDOCImpl();
    ~CDDDbECUDOCImpl();

    void load(const QDomElement &element);

    /** @attribute doctype */
    QString m_doctype;

    /** @attribute dtNesting */
    QString m_dtNesting;

    /** @attribute ftbPoolPath */
    QString m_ftbPoolPath;

    /** @attribute jobfileext */
    QString m_jobfileext;

    /** @attribute languages */
    QString m_languages;

    /** @attribute manufacturer */
    QString m_manufacturer;

    /** @attribute mid */
    QString m_mid;

    /** @attribute oid */
    QString m_oid;

    /** @attribute saveno */
    QString m_saveno;

    /** @attribute temploid */
    QString m_temploid;

    /** @attribute uptodateLanguages */
    QString m_uptodateLanguages;

    /** @attribute xdtauth */
    QString m_xdtauth;

    QString m_text;

    /** @element ATTRCATS */
    QSharedPointer<CDDDbATTRCATS> m_elAttrcats;

    /** @element AUTHORS */
    QSharedPointer<CDDDbAUTHORS> m_elAuthors;

    /** @element DATATYPES */
    QSharedPointer<CDDDbDATATYPES> m_elDatatypes;

    /** @element DCLTMPLS */
    QSharedPointer<CDDDbDCLTMPLS> m_elDcltmpls;

    /** @element DEFATTS */
    QSharedPointer<CDDDbDEFATTS> m_elDefatts;

    /** @element DESC */
    QSharedPointer<CDDDbDESC> m_elDesc;

    /** @element DIDS */
    QSharedPointer<CDDDbDIDS> m_elDids;

    /** @element DOCTMPL */
    QSharedPointer<CDDDbDOCTMPL> m_elDoctmpl;

    /** @element DTCSTATUSMASK */
    QSharedPointer<CDDDbDTCSTATUSMASK> m_elDtcstatusmask;

    /** @element DTID */
    QSharedPointer<CDDDbDTID> m_elDtid;

    /** @element ECU */
    QSharedPointer<CDDDbECU> m_elEcu;

    /** @element HISTITEMS */
    QSharedPointer<CDDDbHISTITEMS> m_elHistitems;

    /** @element NEGRESCODES */
    QSharedPointer<CDDDbNEGRESCODES> m_elNegrescodes;

    /** @element PROTOCOLSERVICES */
    QSharedPointer<CDDDbPROTOCOLSERVICES> m_elProtocolservices;

    /** @element PROTOCOLSTANDARD */
    QSharedPointer<CDDDbPROTOCOLSTANDARD> m_elProtocolstandard;

    /** @element QUALGENOPTIONS */
    QSharedPointer<CDDDbQUALGENOPTIONS> m_elQualgenoptions;

    /** @element RECORDDTPOOL */
    QSharedPointer<CDDDbRECORDDTPOOL> m_elRecorddtpool;

    /** @element RECORDTMPLS */
    QSharedPointer<CDDDbRECORDTMPLS> m_elRecordtmpls;

    /** @element SPECOWNER */
    QSharedPointer<CDDDbSPECOWNER> m_elSpecowner;

    /** @element STATEGROUPS */
    QSharedPointer<CDDDbSTATEGROUPS> m_elStategroups;

    /** @element TARGETGROUPS */
    QSharedPointer<CDDDbTARGETGROUPS> m_elTargetgroups;

    /** @element UNSUPPSRVNEG */
    QSharedPointer<CDDDbUNSUPPSRVNEG> m_elUnsuppsrvneg;

    /** @element VCKMGR */
    QSharedPointer<CDDDbVCKMGR> m_elVckmgr;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBECUDOCIMPL_H

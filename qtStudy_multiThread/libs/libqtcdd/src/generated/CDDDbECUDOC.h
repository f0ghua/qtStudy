#ifndef VECTOR_CDD_CDDDBECUDOC_H
#define VECTOR_CDD_CDDDBECUDOC_H

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
class VECTOR_CDD_API CDDDbECUDOC
{
public:
    CDDDbECUDOC();
    ~CDDDbECUDOC();

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

    /** @element ATTRCATS */
    QSharedPointer<CDDDbATTRCATS> m_attrcats;

    /** @element AUTHORS */
    QSharedPointer<CDDDbAUTHORS> m_authors;

    /** @element DATATYPES */
    QSharedPointer<CDDDbDATATYPES> m_datatypes;

    /** @element DCLTMPLS */
    QSharedPointer<CDDDbDCLTMPLS> m_dcltmpls;

    /** @element DEFATTS */
    QSharedPointer<CDDDbDEFATTS> m_defatts;

    /** @element DESC */
    QSharedPointer<CDDDbDESC> m_desc;

    /** @element DIDS */
    QSharedPointer<CDDDbDIDS> m_dids;

    /** @element DOCTMPL */
    QSharedPointer<CDDDbDOCTMPL> m_doctmpl;

    /** @element DTCSTATUSMASK */
    QSharedPointer<CDDDbDTCSTATUSMASK> m_dtcstatusmask;

    /** @element DTID */
    QSharedPointer<CDDDbDTID> m_dtid;

    /** @element ECU */
    QSharedPointer<CDDDbECU> m_ecu;

    /** @element HISTITEMS */
    QSharedPointer<CDDDbHISTITEMS> m_histitems;

    /** @element NEGRESCODES */
    QSharedPointer<CDDDbNEGRESCODES> m_negrescodes;

    /** @element PROTOCOLSERVICES */
    QSharedPointer<CDDDbPROTOCOLSERVICES> m_protocolservices;

    /** @element PROTOCOLSTANDARD */
    QSharedPointer<CDDDbPROTOCOLSTANDARD> m_protocolstandard;

    /** @element QUALGENOPTIONS */
    QSharedPointer<CDDDbQUALGENOPTIONS> m_qualgenoptions;

    /** @element RECORDDTPOOL */
    QSharedPointer<CDDDbRECORDDTPOOL> m_recorddtpool;

    /** @element RECORDTMPLS */
    QSharedPointer<CDDDbRECORDTMPLS> m_recordtmpls;

    /** @element SPECOWNER */
    QSharedPointer<CDDDbSPECOWNER> m_specowner;

    /** @element STATEGROUPS */
    QSharedPointer<CDDDbSTATEGROUPS> m_stategroups;

    /** @element TARGETGROUPS */
    QSharedPointer<CDDDbTARGETGROUPS> m_targetgroups;

    /** @element UNSUPPSRVNEG */
    QSharedPointer<CDDDbUNSUPPSRVNEG> m_unsuppsrvneg;

    /** @element VCKMGR */
    QSharedPointer<CDDDbVCKMGR> m_vckmgr;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBECUDOC_H

#include "CDDDbATTRCATS.h"
#include "CDDDbAUTHORS.h"
#include "CDDDbDATATYPES.h"
#include "CDDDbDCLTMPLS.h"
#include "CDDDbDEFATTS.h"
#include "CDDDbDESC.h"
#include "CDDDbDIDS.h"
#include "CDDDbDOCTMPL.h"
#include "CDDDbDTCSTATUSMASK.h"
#include "CDDDbDTID.h"
#include "CDDDbECU.h"
#include "CDDDbHISTITEMS.h"
#include "CDDDbNEGRESCODES.h"
#include "CDDDbPROTOCOLSERVICES.h"
#include "CDDDbPROTOCOLSTANDARD.h"
#include "CDDDbQUALGENOPTIONS.h"
#include "CDDDbRECORDDTPOOL.h"
#include "CDDDbRECORDTMPLS.h"
#include "CDDDbSPECOWNER.h"
#include "CDDDbSTATEGROUPS.h"
#include "CDDDbTARGETGROUPS.h"
#include "CDDDbUNSUPPSRVNEG.h"
#include "CDDDbVCKMGR.h"

#include "CDDDbECUDOC.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbECUDOC::CDDDbECUDOC()
{
}

CDDDbECUDOC::~CDDDbECUDOC()
{
}

void CDDDbECUDOC::load(const QDomElement &element)
{
    m_doctype = element.attribute("doctype");
    m_dtNesting = element.attribute("dtNesting");
    m_ftbPoolPath = element.attribute("ftbPoolPath");
    m_jobfileext = element.attribute("jobfileext");
    m_languages = element.attribute("languages");
    m_manufacturer = element.attribute("manufacturer");
    m_mid = element.attribute("mid");
    m_oid = element.attribute("oid");
    m_saveno = element.attribute("saveno");
    m_temploid = element.attribute("temploid");
    m_uptodateLanguages = element.attribute("uptodateLanguages");
    m_xdtauth = element.attribute("xdtauth");

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
        QString elementName = childElement.tagName();
        if (elementName == "ATTRCATS") {
            m_attrcats = QSharedPointer<CDDDbATTRCATS>::create();
            if (m_attrcats) {
                m_attrcats->load(childElement);
            }
        } else if (elementName == "AUTHORS") {
            m_authors = QSharedPointer<CDDDbAUTHORS>::create();
            if (m_authors) {
                m_authors->load(childElement);
            }
        } else if (elementName == "DATATYPES") {
            m_datatypes = QSharedPointer<CDDDbDATATYPES>::create();
            if (m_datatypes) {
                m_datatypes->load(childElement);
            }
        } else if (elementName == "DCLTMPLS") {
            m_dcltmpls = QSharedPointer<CDDDbDCLTMPLS>::create();
            if (m_dcltmpls) {
                m_dcltmpls->load(childElement);
            }
        } else if (elementName == "DEFATTS") {
            m_defatts = QSharedPointer<CDDDbDEFATTS>::create();
            if (m_defatts) {
                m_defatts->load(childElement);
            }
        } else if (elementName == "DESC") {
            m_desc = QSharedPointer<CDDDbDESC>::create();
            if (m_desc) {
                m_desc->load(childElement);
            }
        } else if (elementName == "DIDS") {
            m_dids = QSharedPointer<CDDDbDIDS>::create();
            if (m_dids) {
                m_dids->load(childElement);
            }
        } else if (elementName == "DOCTMPL") {
            m_doctmpl = QSharedPointer<CDDDbDOCTMPL>::create();
            if (m_doctmpl) {
                m_doctmpl->load(childElement);
            }
        } else if (elementName == "DTCSTATUSMASK") {
            m_dtcstatusmask = QSharedPointer<CDDDbDTCSTATUSMASK>::create();
            if (m_dtcstatusmask) {
                m_dtcstatusmask->load(childElement);
            }
        } else if (elementName == "DTID") {
            m_dtid = QSharedPointer<CDDDbDTID>::create();
            if (m_dtid) {
                m_dtid->load(childElement);
            }
        } else if (elementName == "ECU") {
            m_ecu = QSharedPointer<CDDDbECU>::create();
            if (m_ecu) {
                m_ecu->load(childElement);
            }
        } else if (elementName == "HISTITEMS") {
            m_histitems = QSharedPointer<CDDDbHISTITEMS>::create();
            if (m_histitems) {
                m_histitems->load(childElement);
            }
        } else if (elementName == "NEGRESCODES") {
            m_negrescodes = QSharedPointer<CDDDbNEGRESCODES>::create();
            if (m_negrescodes) {
                m_negrescodes->load(childElement);
            }
        } else if (elementName == "PROTOCOLSERVICES") {
            m_protocolservices = QSharedPointer<CDDDbPROTOCOLSERVICES>::create();
            if (m_protocolservices) {
                m_protocolservices->load(childElement);
            }
        } else if (elementName == "PROTOCOLSTANDARD") {
            m_protocolstandard = QSharedPointer<CDDDbPROTOCOLSTANDARD>::create();
            if (m_protocolstandard) {
                m_protocolstandard->load(childElement);
            }
        } else if (elementName == "QUALGENOPTIONS") {
            m_qualgenoptions = QSharedPointer<CDDDbQUALGENOPTIONS>::create();
            if (m_qualgenoptions) {
                m_qualgenoptions->load(childElement);
            }
        } else if (elementName == "RECORDDTPOOL") {
            m_recorddtpool = QSharedPointer<CDDDbRECORDDTPOOL>::create();
            if (m_recorddtpool) {
                m_recorddtpool->load(childElement);
            }
        } else if (elementName == "RECORDTMPLS") {
            m_recordtmpls = QSharedPointer<CDDDbRECORDTMPLS>::create();
            if (m_recordtmpls) {
                m_recordtmpls->load(childElement);
            }
        } else if (elementName == "SPECOWNER") {
            m_specowner = QSharedPointer<CDDDbSPECOWNER>::create();
            if (m_specowner) {
                m_specowner->load(childElement);
            }
        } else if (elementName == "STATEGROUPS") {
            m_stategroups = QSharedPointer<CDDDbSTATEGROUPS>::create();
            if (m_stategroups) {
                m_stategroups->load(childElement);
            }
        } else if (elementName == "TARGETGROUPS") {
            m_targetgroups = QSharedPointer<CDDDbTARGETGROUPS>::create();
            if (m_targetgroups) {
                m_targetgroups->load(childElement);
            }
        } else if (elementName == "UNSUPPSRVNEG") {
            m_unsuppsrvneg = QSharedPointer<CDDDbUNSUPPSRVNEG>::create();
            if (m_unsuppsrvneg) {
                m_unsuppsrvneg->load(childElement);
            }
        } else if (elementName == "VCKMGR") {
            m_vckmgr = QSharedPointer<CDDDbVCKMGR>::create();
            if (m_vckmgr) {
                m_vckmgr->load(childElement);
            }
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector

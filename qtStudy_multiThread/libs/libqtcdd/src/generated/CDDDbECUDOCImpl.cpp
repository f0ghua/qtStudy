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

#include "CDDDbECUDOCImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbECUDOCImpl::CDDDbECUDOCImpl()
{
}

CDDDbECUDOCImpl::~CDDDbECUDOCImpl()
{
}

void CDDDbECUDOCImpl::load(const QDomElement &element)
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
        if (child.isElement()) {
            const QDomElement &childElement = child.toElement();
            QString elementName = childElement.tagName();
            if (elementName == "ATTRCATS") {
                m_elAttrcats = QSharedPointer<CDDDbATTRCATS>::create();
                if (m_elAttrcats) {
                    m_elAttrcats->load(childElement);
                }
            } else if (elementName == "AUTHORS") {
                m_elAuthors = QSharedPointer<CDDDbAUTHORS>::create();
                if (m_elAuthors) {
                    m_elAuthors->load(childElement);
                }
            } else if (elementName == "DATATYPES") {
                m_elDatatypes = QSharedPointer<CDDDbDATATYPES>::create();
                if (m_elDatatypes) {
                    m_elDatatypes->load(childElement);
                }
            } else if (elementName == "DCLTMPLS") {
                m_elDcltmpls = QSharedPointer<CDDDbDCLTMPLS>::create();
                if (m_elDcltmpls) {
                    m_elDcltmpls->load(childElement);
                }
            } else if (elementName == "DEFATTS") {
                m_elDefatts = QSharedPointer<CDDDbDEFATTS>::create();
                if (m_elDefatts) {
                    m_elDefatts->load(childElement);
                }
            } else if (elementName == "DESC") {
                m_elDesc = QSharedPointer<CDDDbDESC>::create();
                if (m_elDesc) {
                    m_elDesc->load(childElement);
                }
            } else if (elementName == "DIDS") {
                m_elDids = QSharedPointer<CDDDbDIDS>::create();
                if (m_elDids) {
                    m_elDids->load(childElement);
                }
            } else if (elementName == "DOCTMPL") {
                m_elDoctmpl = QSharedPointer<CDDDbDOCTMPL>::create();
                if (m_elDoctmpl) {
                    m_elDoctmpl->load(childElement);
                }
            } else if (elementName == "DTCSTATUSMASK") {
                m_elDtcstatusmask = QSharedPointer<CDDDbDTCSTATUSMASK>::create();
                if (m_elDtcstatusmask) {
                    m_elDtcstatusmask->load(childElement);
                }
            } else if (elementName == "DTID") {
                m_elDtid = QSharedPointer<CDDDbDTID>::create();
                if (m_elDtid) {
                    m_elDtid->load(childElement);
                }
            } else if (elementName == "ECU") {
                m_elEcu = QSharedPointer<CDDDbECU>::create();
                if (m_elEcu) {
                    m_elEcu->load(childElement);
                }
            } else if (elementName == "HISTITEMS") {
                m_elHistitems = QSharedPointer<CDDDbHISTITEMS>::create();
                if (m_elHistitems) {
                    m_elHistitems->load(childElement);
                }
            } else if (elementName == "NEGRESCODES") {
                m_elNegrescodes = QSharedPointer<CDDDbNEGRESCODES>::create();
                if (m_elNegrescodes) {
                    m_elNegrescodes->load(childElement);
                }
            } else if (elementName == "PROTOCOLSERVICES") {
                m_elProtocolservices = QSharedPointer<CDDDbPROTOCOLSERVICES>::create();
                if (m_elProtocolservices) {
                    m_elProtocolservices->load(childElement);
                }
            } else if (elementName == "PROTOCOLSTANDARD") {
                m_elProtocolstandard = QSharedPointer<CDDDbPROTOCOLSTANDARD>::create();
                if (m_elProtocolstandard) {
                    m_elProtocolstandard->load(childElement);
                }
            } else if (elementName == "QUALGENOPTIONS") {
                m_elQualgenoptions = QSharedPointer<CDDDbQUALGENOPTIONS>::create();
                if (m_elQualgenoptions) {
                    m_elQualgenoptions->load(childElement);
                }
            } else if (elementName == "RECORDDTPOOL") {
                m_elRecorddtpool = QSharedPointer<CDDDbRECORDDTPOOL>::create();
                if (m_elRecorddtpool) {
                    m_elRecorddtpool->load(childElement);
                }
            } else if (elementName == "RECORDTMPLS") {
                m_elRecordtmpls = QSharedPointer<CDDDbRECORDTMPLS>::create();
                if (m_elRecordtmpls) {
                    m_elRecordtmpls->load(childElement);
                }
            } else if (elementName == "SPECOWNER") {
                m_elSpecowner = QSharedPointer<CDDDbSPECOWNER>::create();
                if (m_elSpecowner) {
                    m_elSpecowner->load(childElement);
                }
            } else if (elementName == "STATEGROUPS") {
                m_elStategroups = QSharedPointer<CDDDbSTATEGROUPS>::create();
                if (m_elStategroups) {
                    m_elStategroups->load(childElement);
                }
            } else if (elementName == "TARGETGROUPS") {
                m_elTargetgroups = QSharedPointer<CDDDbTARGETGROUPS>::create();
                if (m_elTargetgroups) {
                    m_elTargetgroups->load(childElement);
                }
            } else if (elementName == "UNSUPPSRVNEG") {
                m_elUnsuppsrvneg = QSharedPointer<CDDDbUNSUPPSRVNEG>::create();
                if (m_elUnsuppsrvneg) {
                    m_elUnsuppsrvneg->load(childElement);
                }
            } else if (elementName == "VCKMGR") {
                m_elVckmgr = QSharedPointer<CDDDbVCKMGR>::create();
                if (m_elVckmgr) {
                    m_elVckmgr->load(childElement);
                }
            }
        } else if (child.isText()) {
            m_text = element.text();
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector

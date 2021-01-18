#include "CDDDbDATAOBJATTS.h"
#include "CDDDbDATATYPEATTS.h"
#include "CDDDbDCLSRVTMPLATTS.h"
#include "CDDDbDCLTMPLATTS.h"
#include "CDDDbDIAGCLASSATTS.h"
#include "CDDDbDIAGINSTATTS.h"
#include "CDDDbDIDATTS.h"
#include "CDDDbECUATTS.h"
#include "CDDDbJOBATTS.h"
#include "CDDDbJOBCNRATTS.h"
#include "CDDDbRECORDATTS.h"
#include "CDDDbSERVICEATTS.h"
#include "CDDDbSHPROXYATTS.h"
#include "CDDDbSTATEGROUPATTS.h"
#include "CDDDbVARATTS.h"

#include "CDDDbDEFATTSImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbDEFATTSImpl::CDDDbDEFATTSImpl()
{
}

CDDDbDEFATTSImpl::~CDDDbDEFATTSImpl()
{
}

void CDDDbDEFATTSImpl::load(const QDomElement &element)
{
    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        if (child.isElement()) {
            const QDomElement &childElement = child.toElement();
            QString elementName = childElement.tagName();
            if (elementName == "DATAOBJATTS") {
                m_elDataobjatts = QSharedPointer<CDDDbDATAOBJATTS>::create();
                if (m_elDataobjatts) {
                    m_elDataobjatts->load(childElement);
                }
            } else if (elementName == "DATATYPEATTS") {
                m_elDatatypeatts = QSharedPointer<CDDDbDATATYPEATTS>::create();
                if (m_elDatatypeatts) {
                    m_elDatatypeatts->load(childElement);
                }
            } else if (elementName == "DCLSRVTMPLATTS") {
                m_elDclsrvtmplatts = QSharedPointer<CDDDbDCLSRVTMPLATTS>::create();
                if (m_elDclsrvtmplatts) {
                    m_elDclsrvtmplatts->load(childElement);
                }
            } else if (elementName == "DCLTMPLATTS") {
                m_elDcltmplatts = QSharedPointer<CDDDbDCLTMPLATTS>::create();
                if (m_elDcltmplatts) {
                    m_elDcltmplatts->load(childElement);
                }
            } else if (elementName == "DIAGCLASSATTS") {
                m_elDiagclassatts = QSharedPointer<CDDDbDIAGCLASSATTS>::create();
                if (m_elDiagclassatts) {
                    m_elDiagclassatts->load(childElement);
                }
            } else if (elementName == "DIAGINSTATTS") {
                m_elDiaginstatts = QSharedPointer<CDDDbDIAGINSTATTS>::create();
                if (m_elDiaginstatts) {
                    m_elDiaginstatts->load(childElement);
                }
            } else if (elementName == "DIDATTS") {
                m_elDidatts = QSharedPointer<CDDDbDIDATTS>::create();
                if (m_elDidatts) {
                    m_elDidatts->load(childElement);
                }
            } else if (elementName == "ECUATTS") {
                m_elEcuatts = QSharedPointer<CDDDbECUATTS>::create();
                if (m_elEcuatts) {
                    m_elEcuatts->load(childElement);
                }
            } else if (elementName == "JOBATTS") {
                m_elJobatts = QSharedPointer<CDDDbJOBATTS>::create();
                if (m_elJobatts) {
                    m_elJobatts->load(childElement);
                }
            } else if (elementName == "JOBCNRATTS") {
                m_elJobcnratts = QSharedPointer<CDDDbJOBCNRATTS>::create();
                if (m_elJobcnratts) {
                    m_elJobcnratts->load(childElement);
                }
            } else if (elementName == "RECORDATTS") {
                m_elRecordatts = QSharedPointer<CDDDbRECORDATTS>::create();
                if (m_elRecordatts) {
                    m_elRecordatts->load(childElement);
                }
            } else if (elementName == "SERVICEATTS") {
                m_elServiceatts = QSharedPointer<CDDDbSERVICEATTS>::create();
                if (m_elServiceatts) {
                    m_elServiceatts->load(childElement);
                }
            } else if (elementName == "SHPROXYATTS") {
                m_elShproxyatts = QSharedPointer<CDDDbSHPROXYATTS>::create();
                if (m_elShproxyatts) {
                    m_elShproxyatts->load(childElement);
                }
            } else if (elementName == "STATEGROUPATTS") {
                m_elStategroupatts = QSharedPointer<CDDDbSTATEGROUPATTS>::create();
                if (m_elStategroupatts) {
                    m_elStategroupatts->load(childElement);
                }
            } else if (elementName == "VARATTS") {
                m_elVaratts = QSharedPointer<CDDDbVARATTS>::create();
                if (m_elVaratts) {
                    m_elVaratts->load(childElement);
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

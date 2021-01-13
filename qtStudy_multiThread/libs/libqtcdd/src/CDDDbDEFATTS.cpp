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

#include "CDDDbDEFATTS.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbDEFATTS::CDDDbDEFATTS()
{
}

CDDDbDEFATTS::~CDDDbDEFATTS()
{
}

void CDDDbDEFATTS::load(const QDomElement &element)
{

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
        QString elementName = childElement.tagName();
        if (elementName == "DATAOBJATTS") {
            m_dataobjatts = QSharedPointer<CDDDbDATAOBJATTS>::create();
            if (m_dataobjatts) {
                m_dataobjatts->load(childElement);
            }
        } else if (elementName == "DATATYPEATTS") {
            m_datatypeatts = QSharedPointer<CDDDbDATATYPEATTS>::create();
            if (m_datatypeatts) {
                m_datatypeatts->load(childElement);
            }
        } else if (elementName == "DCLSRVTMPLATTS") {
            m_dclsrvtmplatts = QSharedPointer<CDDDbDCLSRVTMPLATTS>::create();
            if (m_dclsrvtmplatts) {
                m_dclsrvtmplatts->load(childElement);
            }
        } else if (elementName == "DCLTMPLATTS") {
            m_dcltmplatts = QSharedPointer<CDDDbDCLTMPLATTS>::create();
            if (m_dcltmplatts) {
                m_dcltmplatts->load(childElement);
            }
        } else if (elementName == "DIAGCLASSATTS") {
            m_diagclassatts = QSharedPointer<CDDDbDIAGCLASSATTS>::create();
            if (m_diagclassatts) {
                m_diagclassatts->load(childElement);
            }
        } else if (elementName == "DIAGINSTATTS") {
            m_diaginstatts = QSharedPointer<CDDDbDIAGINSTATTS>::create();
            if (m_diaginstatts) {
                m_diaginstatts->load(childElement);
            }
        } else if (elementName == "DIDATTS") {
            m_didatts = QSharedPointer<CDDDbDIDATTS>::create();
            if (m_didatts) {
                m_didatts->load(childElement);
            }
        } else if (elementName == "ECUATTS") {
            m_ecuatts = QSharedPointer<CDDDbECUATTS>::create();
            if (m_ecuatts) {
                m_ecuatts->load(childElement);
            }
        } else if (elementName == "JOBATTS") {
            m_jobatts = QSharedPointer<CDDDbJOBATTS>::create();
            if (m_jobatts) {
                m_jobatts->load(childElement);
            }
        } else if (elementName == "JOBCNRATTS") {
            m_jobcnratts = QSharedPointer<CDDDbJOBCNRATTS>::create();
            if (m_jobcnratts) {
                m_jobcnratts->load(childElement);
            }
        } else if (elementName == "RECORDATTS") {
            m_recordatts = QSharedPointer<CDDDbRECORDATTS>::create();
            if (m_recordatts) {
                m_recordatts->load(childElement);
            }
        } else if (elementName == "SERVICEATTS") {
            m_serviceatts = QSharedPointer<CDDDbSERVICEATTS>::create();
            if (m_serviceatts) {
                m_serviceatts->load(childElement);
            }
        } else if (elementName == "SHPROXYATTS") {
            m_shproxyatts = QSharedPointer<CDDDbSHPROXYATTS>::create();
            if (m_shproxyatts) {
                m_shproxyatts->load(childElement);
            }
        } else if (elementName == "STATEGROUPATTS") {
            m_stategroupatts = QSharedPointer<CDDDbSTATEGROUPATTS>::create();
            if (m_stategroupatts) {
                m_stategroupatts->load(childElement);
            }
        } else if (elementName == "VARATTS") {
            m_varatts = QSharedPointer<CDDDbVARATTS>::create();
            if (m_varatts) {
                m_varatts->load(childElement);
            }
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector

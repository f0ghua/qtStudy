#include "CDDDbCOMMONSNAPSHOTDATAPOOL.h"
#include "CDDDbEXTENDEDDATARECORDS.h"
#include "CDDDbSNAPSHOTRECORDS.h"

#include "CDDDbFAULTMEMORYImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbFAULTMEMORYImpl::CDDDbFAULTMEMORYImpl()
{
}

CDDDbFAULTMEMORYImpl::~CDDDbFAULTMEMORYImpl()
{
}

void CDDDbFAULTMEMORYImpl::load(const QDomElement &element)
{
    m_dnDtRef = element.attribute("dnDtRef");
    m_forceDidSnapshotData = element.attribute("forceDidSnapshotData");
    m_forceSameSnapshotData = element.attribute("forceSameSnapshotData");
    m_mayBeAddDelEdr = element.attribute("mayBeAddDelEdr");
    m_mayBeAddDelSr = element.attribute("mayBeAddDelSr");
    m_supportDtcSpecificData = element.attribute("supportDtcSpecificData");
    m_supportEdrForDtc = element.attribute("supportEdrForDtc");

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        if (child.isElement()) {
            const QDomElement &childElement = child.toElement();
            QString elementName = childElement.tagName();
            if (elementName == "COMMONSNAPSHOTDATAPOOL") {
                m_elCommonsnapshotdatapool = QSharedPointer<CDDDbCOMMONSNAPSHOTDATAPOOL>::create();
                if (m_elCommonsnapshotdatapool) {
                    m_elCommonsnapshotdatapool->load(childElement);
                }
            } else if (elementName == "EXTENDEDDATARECORDS") {
                m_elExtendeddatarecords = QSharedPointer<CDDDbEXTENDEDDATARECORDS>::create();
                if (m_elExtendeddatarecords) {
                    m_elExtendeddatarecords->load(childElement);
                }
            } else if (elementName == "SNAPSHOTRECORDS") {
                m_elSnapshotrecords = QSharedPointer<CDDDbSNAPSHOTRECORDS>::create();
                if (m_elSnapshotrecords) {
                    m_elSnapshotrecords->load(childElement);
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

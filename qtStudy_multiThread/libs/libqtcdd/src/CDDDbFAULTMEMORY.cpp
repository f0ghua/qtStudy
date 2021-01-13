#include "CDDDbCOMMONSNAPSHOTDATAPOOL.h"
#include "CDDDbEXTENDEDDATARECORDS.h"
#include "CDDDbSNAPSHOTRECORDS.h"

#include "CDDDbFAULTMEMORY.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbFAULTMEMORY::CDDDbFAULTMEMORY()
{
}

CDDDbFAULTMEMORY::~CDDDbFAULTMEMORY()
{
}

void CDDDbFAULTMEMORY::load(const QDomElement &element)
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
        const QDomElement &childElement = child.toElement();
        QString elementName = childElement.tagName();
        if (elementName == "COMMONSNAPSHOTDATAPOOL") {
            m_commonsnapshotdatapool = QSharedPointer<CDDDbCOMMONSNAPSHOTDATAPOOL>::create();
            if (m_commonsnapshotdatapool) {
                m_commonsnapshotdatapool->load(childElement);
            }
        } else if (elementName == "EXTENDEDDATARECORDS") {
            m_extendeddatarecords = QSharedPointer<CDDDbEXTENDEDDATARECORDS>::create();
            if (m_extendeddatarecords) {
                m_extendeddatarecords->load(childElement);
            }
        } else if (elementName == "SNAPSHOTRECORDS") {
            m_snapshotrecords = QSharedPointer<CDDDbSNAPSHOTRECORDS>::create();
            if (m_snapshotrecords) {
                m_snapshotrecords->load(childElement);
            }
        }
        child = child.nextSibling();
    }
}

} // namespace cdd
} // namespace vector

#include "CDDDbDATAOBJ.h"
#include "CDDDbDIDDATAREF.h"
#include "CDDDbGODTCDATAOBJ.h"
#include "CDDDbRECORDDATAOBJ.h"
#include "CDDDbSPECDATAOBJ.h"
#include "CDDDbSTRUCT.h"

#include "CDDDbSIMPLECOMPCONTImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbSIMPLECOMPCONTImpl::CDDDbSIMPLECOMPCONTImpl()
{
}

CDDDbSIMPLECOMPCONTImpl::~CDDDbSIMPLECOMPCONTImpl()
{
}

void CDDDbSIMPLECOMPCONTImpl::load(const QDomElement &element)
{
    m_oid = element.attribute("oid");
    m_shproxyref = element.attribute("shproxyref");
    m_temploid = element.attribute("temploid");

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        if (child.isElement()) {
            const QDomElement &childElement = child.toElement();
            QString elementName = childElement.tagName();
            if (elementName == "DATAOBJ") {
                auto o = QSharedPointer<CDDDbDATAOBJ>::create();
                if (o) {
                    o->load(childElement);
                    if (!o->m_id.isEmpty()) {
                        m_elDataobjs.insert(o->m_id, o);
                    }
                }
            } else if (elementName == "DIDDATAREF") {
                m_elDiddataref = QSharedPointer<CDDDbDIDDATAREF>::create();
                if (m_elDiddataref) {
                    m_elDiddataref->load(childElement);
                }
            } else if (elementName == "GODTCDATAOBJ") {
                m_elGodtcdataobj = QSharedPointer<CDDDbGODTCDATAOBJ>::create();
                if (m_elGodtcdataobj) {
                    m_elGodtcdataobj->load(childElement);
                }
            } else if (elementName == "RECORDDATAOBJ") {
                m_elRecorddataobj = QSharedPointer<CDDDbRECORDDATAOBJ>::create();
                if (m_elRecorddataobj) {
                    m_elRecorddataobj->load(childElement);
                }
            } else if (elementName == "SPECDATAOBJ") {
                m_elSpecdataobj = QSharedPointer<CDDDbSPECDATAOBJ>::create();
                if (m_elSpecdataobj) {
                    m_elSpecdataobj->load(childElement);
                }
            } else if (elementName == "STRUCT") {
                auto o = QSharedPointer<CDDDbSTRUCT>::create();
                if (o) {
                    o->load(childElement);
                    m_elStructs.append(o);
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

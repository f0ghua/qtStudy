#include "CDDDbUNIT.h"

#include "CDDDbPVALUETYPEImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbPVALUETYPEImpl::CDDDbPVALUETYPEImpl()
{
}

CDDDbPVALUETYPEImpl::~CDDDbPVALUETYPEImpl()
{
}

void CDDDbPVALUETYPEImpl::load(const QDomElement &element)
{
    m_bl = element.attribute("bl");
    m_bo = element.attribute("bo");
    m_df = element.attribute("df");
    m_enc = element.attribute("enc");
    m_maxsz = element.attribute("maxsz");
    m_minsz = element.attribute("minsz");
    m_qty = element.attribute("qty");
    m_sig = element.attribute("sig");
    m_sz = element.attribute("sz");

    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        if (child.isElement()) {
            const QDomElement &childElement = child.toElement();
            QString elementName = childElement.tagName();
            if (elementName == "UNIT") {
                m_elUnit = QSharedPointer<CDDDbUNIT>::create();
                if (m_elUnit) {
                    m_elUnit->load(childElement);
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


#include "CDDDbUNSRECORDITEMImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbUNSRECORDITEMImpl::CDDDbUNSRECORDITEMImpl()
{
}

CDDDbUNSRECORDITEMImpl::~CDDDbUNSRECORDITEMImpl()
{
}

void CDDDbUNSRECORDITEMImpl::load(const QDomElement &element)
{
    m_idref = element.attribute("idref");
    m_v = element.attribute("v");

}

} // namespace cdd
} // namespace vector

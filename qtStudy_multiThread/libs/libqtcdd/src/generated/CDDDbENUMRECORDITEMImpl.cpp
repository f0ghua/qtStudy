
#include "CDDDbENUMRECORDITEMImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbENUMRECORDITEMImpl::CDDDbENUMRECORDITEMImpl()
{
}

CDDDbENUMRECORDITEMImpl::~CDDDbENUMRECORDITEMImpl()
{
}

void CDDDbENUMRECORDITEMImpl::load(const QDomElement &element)
{
    m_idref = element.attribute("idref");
    m_v = element.attribute("v");

}

} // namespace cdd
} // namespace vector


#include "CDDDbVCKMGRImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbVCKMGRImpl::CDDDbVCKMGRImpl()
{
}

CDDDbVCKMGRImpl::~CDDDbVCKMGRImpl()
{
}

void CDDDbVCKMGRImpl::load(const QDomElement &element)
{
    m_vckmax = element.attribute("vckmax");
    m_vckmin = element.attribute("vckmin");
    m_vckmode = element.attribute("vckmode");
    m_vcknext = element.attribute("vcknext");

}

} // namespace cdd
} // namespace vector


#include "CDDDbVCKMGR.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbVCKMGR::CDDDbVCKMGR()
{
}

CDDDbVCKMGR::~CDDDbVCKMGR()
{
}

void CDDDbVCKMGR::load(const QDomElement &element)
{
    m_vckmax = element.attribute("vckmax");
    m_vckmin = element.attribute("vckmin");
    m_vckmode = element.attribute("vckmode");
    m_vcknext = element.attribute("vcknext");

}

} // namespace cdd
} // namespace vector

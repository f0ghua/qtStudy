
#include "CDDDbCOMPImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbCOMPImpl::CDDDbCOMPImpl()
{
}

CDDDbCOMPImpl::~CDDDbCOMPImpl()
{
}

void CDDDbCOMPImpl::load(const QDomElement &element)
{
    m_div = element.attribute("div");
    m_e = element.attribute("e");
    m_f = element.attribute("f");
    m_o = element.attribute("o");
    m_s = element.attribute("s");

}

} // namespace cdd
} // namespace vector

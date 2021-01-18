
#include "CDDDbSPECOWNERImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbSPECOWNERImpl::CDDDbSPECOWNERImpl()
{
}

CDDDbSPECOWNERImpl::~CDDDbSPECOWNERImpl()
{
}

void CDDDbSPECOWNERImpl::load(const QDomElement &element)
{
    m_text = element.text();
}

} // namespace cdd
} // namespace vector

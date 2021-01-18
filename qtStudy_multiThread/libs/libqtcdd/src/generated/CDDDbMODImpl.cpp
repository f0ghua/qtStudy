
#include "CDDDbMODImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbMODImpl::CDDDbMODImpl()
{
}

CDDDbMODImpl::~CDDDbMODImpl()
{
}

void CDDDbMODImpl::load(const QDomElement &element)
{
    m_text = element.text();
}

} // namespace cdd
} // namespace vector

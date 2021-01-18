
#include "CDDDbCOMMONSTRINGImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbCOMMONSTRINGImpl::CDDDbCOMMONSTRINGImpl()
{
}

CDDDbCOMMONSTRINGImpl::~CDDDbCOMMONSTRINGImpl()
{
}

void CDDDbCOMMONSTRINGImpl::load(const QDomElement &element)
{
    m_text = element.text();
}

} // namespace cdd
} // namespace vector

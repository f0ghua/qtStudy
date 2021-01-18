
#include "CDDDbPROTOCOLSTANDARDImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbPROTOCOLSTANDARDImpl::CDDDbPROTOCOLSTANDARDImpl()
{
}

CDDDbPROTOCOLSTANDARDImpl::~CDDDbPROTOCOLSTANDARDImpl()
{
}

void CDDDbPROTOCOLSTANDARDImpl::load(const QDomElement &element)
{
    m_text = element.text();
}

} // namespace cdd
} // namespace vector

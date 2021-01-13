
#include "CDDDbSPECOWNER.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbSPECOWNER::CDDDbSPECOWNER()
{
}

CDDDbSPECOWNER::~CDDDbSPECOWNER()
{
}

void CDDDbSPECOWNER::load(const QDomElement &element)
{

    m_text = element.text();
}

} // namespace cdd
} // namespace vector

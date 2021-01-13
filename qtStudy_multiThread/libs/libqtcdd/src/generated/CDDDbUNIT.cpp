
#include "CDDDbUNIT.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbUNIT::CDDDbUNIT()
{
}

CDDDbUNIT::~CDDDbUNIT()
{
}

void CDDDbUNIT::load(const QDomElement &element)
{

    m_text = element.text();
}

} // namespace cdd
} // namespace vector


#include "CDDDbFC.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbFC::CDDDbFC()
{
}

CDDDbFC::~CDDDbFC()
{
}

void CDDDbFC::load(const QDomElement &element)
{

    m_text = element.text();
}

} // namespace cdd
} // namespace vector

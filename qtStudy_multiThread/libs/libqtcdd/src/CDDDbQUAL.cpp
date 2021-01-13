
#include "CDDDbQUAL.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbQUAL::CDDDbQUAL()
{
}

CDDDbQUAL::~CDDDbQUAL()
{
}

void CDDDbQUAL::load(const QDomElement &element)
{

    m_text = element.text();
}

} // namespace cdd
} // namespace vector

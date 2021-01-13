
#include "CDDDbLABEL.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbLABEL::CDDDbLABEL()
{
}

CDDDbLABEL::~CDDDbLABEL()
{
}

void CDDDbLABEL::load(const QDomElement &element)
{

    m_text = element.text();
}

} // namespace cdd
} // namespace vector

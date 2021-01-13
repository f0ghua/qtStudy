
#include "CDDDbSHORTCUTQUAL.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbSHORTCUTQUAL::CDDDbSHORTCUTQUAL()
{
}

CDDDbSHORTCUTQUAL::~CDDDbSHORTCUTQUAL()
{
}

void CDDDbSHORTCUTQUAL::load(const QDomElement &element)
{

    m_text = element.text();
}

} // namespace cdd
} // namespace vector


#include "CDDDbMOD.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbMOD::CDDDbMOD()
{
}

CDDDbMOD::~CDDDbMOD()
{
}

void CDDDbMOD::load(const QDomElement &element)
{

    m_text = element.text();
}

} // namespace cdd
} // namespace vector

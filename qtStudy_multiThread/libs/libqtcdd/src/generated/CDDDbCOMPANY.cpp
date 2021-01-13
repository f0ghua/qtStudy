
#include "CDDDbCOMPANY.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbCOMPANY::CDDDbCOMPANY()
{
}

CDDDbCOMPANY::~CDDDbCOMPANY()
{
}

void CDDDbCOMPANY::load(const QDomElement &element)
{

    m_text = element.text();
}

} // namespace cdd
} // namespace vector


#include "CDDDbCOMMONSTRING.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbCOMMONSTRING::CDDDbCOMMONSTRING()
{
}

CDDDbCOMMONSTRING::~CDDDbCOMMONSTRING()
{
}

void CDDDbCOMMONSTRING::load(const QDomElement &element)
{

    m_text = element.text();
}

} // namespace cdd
} // namespace vector

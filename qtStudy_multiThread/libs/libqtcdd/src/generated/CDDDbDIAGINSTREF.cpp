
#include "CDDDbDIAGINSTREF.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbDIAGINSTREF::CDDDbDIAGINSTREF()
{
}

CDDDbDIAGINSTREF::~CDDDbDIAGINSTREF()
{
}

void CDDDbDIAGINSTREF::load(const QDomElement &element)
{
    m_idref = element.attribute("idref");

}

} // namespace cdd
} // namespace vector

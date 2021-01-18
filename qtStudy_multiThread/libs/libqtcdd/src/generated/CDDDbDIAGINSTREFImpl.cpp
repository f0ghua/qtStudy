
#include "CDDDbDIAGINSTREFImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbDIAGINSTREFImpl::CDDDbDIAGINSTREFImpl()
{
}

CDDDbDIAGINSTREFImpl::~CDDDbDIAGINSTREFImpl()
{
}

void CDDDbDIAGINSTREFImpl::load(const QDomElement &element)
{
    m_idref = element.attribute("idref");

}

} // namespace cdd
} // namespace vector


#include "CDDDbDIDREFImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbDIDREFImpl::CDDDbDIDREFImpl()
{
}

CDDDbDIDREFImpl::~CDDDbDIDREFImpl()
{
}

void CDDDbDIDREFImpl::load(const QDomElement &element)
{
    m_didRef = element.attribute("didRef");

}

} // namespace cdd
} // namespace vector


#include "CDDDbJOBCNRREFImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbJOBCNRREFImpl::CDDDbJOBCNRREFImpl()
{
}

CDDDbJOBCNRREFImpl::~CDDDbJOBCNRREFImpl()
{
}

void CDDDbJOBCNRREFImpl::load(const QDomElement &element)
{
    m_idref = element.attribute("idref");

}

} // namespace cdd
} // namespace vector

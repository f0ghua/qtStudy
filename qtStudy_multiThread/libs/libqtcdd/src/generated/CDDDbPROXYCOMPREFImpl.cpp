
#include "CDDDbPROXYCOMPREFImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbPROXYCOMPREFImpl::CDDDbPROXYCOMPREFImpl()
{
}

CDDDbPROXYCOMPREFImpl::~CDDDbPROXYCOMPREFImpl()
{
}

void CDDDbPROXYCOMPREFImpl::load(const QDomElement &element)
{
    m_idref = element.attribute("idref");

}

} // namespace cdd
} // namespace vector

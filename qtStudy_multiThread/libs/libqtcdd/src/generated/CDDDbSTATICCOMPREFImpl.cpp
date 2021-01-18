
#include "CDDDbSTATICCOMPREFImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbSTATICCOMPREFImpl::CDDDbSTATICCOMPREFImpl()
{
}

CDDDbSTATICCOMPREFImpl::~CDDDbSTATICCOMPREFImpl()
{
}

void CDDDbSTATICCOMPREFImpl::load(const QDomElement &element)
{
    m_idref = element.attribute("idref");

}

} // namespace cdd
} // namespace vector

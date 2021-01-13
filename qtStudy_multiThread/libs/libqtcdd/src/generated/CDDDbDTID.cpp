
#include "CDDDbDTID.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbDTID::CDDDbDTID()
{
}

CDDDbDTID::~CDDDbDTID()
{
}

void CDDDbDTID::load(const QDomElement &element)
{

    m_text = element.text();
}

} // namespace cdd
} // namespace vector

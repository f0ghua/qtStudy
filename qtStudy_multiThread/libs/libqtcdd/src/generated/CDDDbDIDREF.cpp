
#include "CDDDbDIDREF.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbDIDREF::CDDDbDIDREF()
{
}

CDDDbDIDREF::~CDDDbDIDREF()
{
}

void CDDDbDIDREF::load(const QDomElement &element)
{
    m_didRef = element.attribute("didRef");

}

} // namespace cdd
} // namespace vector

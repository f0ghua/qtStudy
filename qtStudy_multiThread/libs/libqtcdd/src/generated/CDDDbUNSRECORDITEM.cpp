
#include "CDDDbUNSRECORDITEM.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbUNSRECORDITEM::CDDDbUNSRECORDITEM()
{
}

CDDDbUNSRECORDITEM::~CDDDbUNSRECORDITEM()
{
}

void CDDDbUNSRECORDITEM::load(const QDomElement &element)
{
    m_idref = element.attribute("idref");
    m_v = element.attribute("v");

}

} // namespace cdd
} // namespace vector

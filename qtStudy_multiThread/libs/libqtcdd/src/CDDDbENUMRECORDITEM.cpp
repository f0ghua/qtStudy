
#include "CDDDbENUMRECORDITEM.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbENUMRECORDITEM::CDDDbENUMRECORDITEM()
{
}

CDDDbENUMRECORDITEM::~CDDDbENUMRECORDITEM()
{
}

void CDDDbENUMRECORDITEM::load(const QDomElement &element)
{
    m_idref = element.attribute("idref");
    m_v = element.attribute("v");

}

} // namespace cdd
} // namespace vector

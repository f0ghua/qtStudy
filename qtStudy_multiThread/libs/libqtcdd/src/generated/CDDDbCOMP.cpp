
#include "CDDDbCOMP.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbCOMP::CDDDbCOMP()
{
}

CDDDbCOMP::~CDDDbCOMP()
{
}

void CDDDbCOMP::load(const QDomElement &element)
{
    m_f = element.attribute("f");
    m_o = element.attribute("o");

}

} // namespace cdd
} // namespace vector

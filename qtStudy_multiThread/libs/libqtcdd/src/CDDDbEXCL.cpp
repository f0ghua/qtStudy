
#include "CDDDbEXCL.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbEXCL::CDDDbEXCL()
{
}

CDDDbEXCL::~CDDDbEXCL()
{
}

void CDDDbEXCL::load(const QDomElement &element)
{
    m_e = element.attribute("e");
    m_inv = element.attribute("inv");
    m_s = element.attribute("s");

}

} // namespace cdd
} // namespace vector

#include "CDDLog.h"
#include "CDDDbAttrCatRefType.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbAttrCatRefType::CDDDbAttrCatRefType()
{
}

CDDDbAttrCatRefType::~CDDDbAttrCatRefType()
{

}

void CDDDbAttrCatRefType::load(const QDomElement &element)
{
    m_attrcatref = element.attribute("attrcatref");
}

} // namespace cdd
} // namespace vector

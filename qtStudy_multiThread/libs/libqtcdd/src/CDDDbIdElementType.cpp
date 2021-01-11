#include "CDDLog.h"
#include "CDDDbIdElementType.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbIdElementType::CDDDbIdElementType()
{
}

CDDDbIdElementType::~CDDDbIdElementType()
{

}

void CDDDbIdElementType::load(const QDomElement &element)
{
    m_id = element.attribute("ID");
}

} // namespace cdd
} // namespace vector
#include "CDDLog.h"
#include "CDDDbQual.h"
#include "CDDDbTuv.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbQual::CDDDbQual()
{
}

CDDDbQual::~CDDDbQual()
{

}

void CDDDbQual::load(const QDomElement &element)
{
    m_value = element.text();
}

} // namespace cdd
} // namespace vector

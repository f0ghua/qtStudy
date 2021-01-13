
#include "CDDDbSHORTNAME.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbSHORTNAME::CDDDbSHORTNAME()
{
}

CDDDbSHORTNAME::~CDDDbSHORTNAME()
{
}

void CDDDbSHORTNAME::load(const QDomElement &element)
{

    m_text = element.text();
}

} // namespace cdd
} // namespace vector

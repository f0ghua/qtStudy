
#include "CDDDbFIRSTNAME.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbFIRSTNAME::CDDDbFIRSTNAME()
{
}

CDDDbFIRSTNAME::~CDDDbFIRSTNAME()
{
}

void CDDDbFIRSTNAME::load(const QDomElement &element)
{

    m_text = element.text();
}

} // namespace cdd
} // namespace vector


#include "CDDDbLASTNAME.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbLASTNAME::CDDDbLASTNAME()
{
}

CDDDbLASTNAME::~CDDDbLASTNAME()
{
}

void CDDDbLASTNAME::load(const QDomElement &element)
{

    m_text = element.text();
}

} // namespace cdd
} // namespace vector

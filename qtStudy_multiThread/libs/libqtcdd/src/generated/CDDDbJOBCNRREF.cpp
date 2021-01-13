
#include "CDDDbJOBCNRREF.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbJOBCNRREF::CDDDbJOBCNRREF()
{
}

CDDDbJOBCNRREF::~CDDDbJOBCNRREF()
{
}

void CDDDbJOBCNRREF::load(const QDomElement &element)
{
    m_idref = element.attribute("idref");

}

} // namespace cdd
} // namespace vector

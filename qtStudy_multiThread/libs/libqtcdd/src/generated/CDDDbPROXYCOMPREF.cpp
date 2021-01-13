
#include "CDDDbPROXYCOMPREF.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbPROXYCOMPREF::CDDDbPROXYCOMPREF()
{
}

CDDDbPROXYCOMPREF::~CDDDbPROXYCOMPREF()
{
}

void CDDDbPROXYCOMPREF::load(const QDomElement &element)
{
    m_idref = element.attribute("idref");

}

} // namespace cdd
} // namespace vector

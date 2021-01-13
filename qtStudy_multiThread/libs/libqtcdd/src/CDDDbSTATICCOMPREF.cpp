
#include "CDDDbSTATICCOMPREF.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbSTATICCOMPREF::CDDDbSTATICCOMPREF()
{
}

CDDDbSTATICCOMPREF::~CDDDbSTATICCOMPREF()
{
}

void CDDDbSTATICCOMPREF::load(const QDomElement &element)
{
    m_idref = element.attribute("idref");

}

} // namespace cdd
} // namespace vector

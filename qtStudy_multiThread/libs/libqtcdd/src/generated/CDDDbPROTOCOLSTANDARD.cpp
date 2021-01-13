
#include "CDDDbPROTOCOLSTANDARD.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbPROTOCOLSTANDARD::CDDDbPROTOCOLSTANDARD()
{
}

CDDDbPROTOCOLSTANDARD::~CDDDbPROTOCOLSTANDARD()
{
}

void CDDDbPROTOCOLSTANDARD::load(const QDomElement &element)
{

    m_text = element.text();
}

} // namespace cdd
} // namespace vector

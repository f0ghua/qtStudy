
#include "CDDDbPROTOCOLSTANDARD.h"

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
    CDDDbPROTOCOLSTANDARDImpl::load(element);
}

} // namespace cdd
} // namespace vector

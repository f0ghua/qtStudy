#include "CDDDbPROTOCOLSERVICE.h"

#include "CDDDbPROTOCOLSERVICES.h"

namespace vector {
namespace cdd {

CDDDbPROTOCOLSERVICES::CDDDbPROTOCOLSERVICES()
{
}

CDDDbPROTOCOLSERVICES::~CDDDbPROTOCOLSERVICES()
{
}

void CDDDbPROTOCOLSERVICES::load(const QDomElement &element)
{
    CDDDbPROTOCOLSERVICESImpl::load(element);
}

} // namespace cdd
} // namespace vector

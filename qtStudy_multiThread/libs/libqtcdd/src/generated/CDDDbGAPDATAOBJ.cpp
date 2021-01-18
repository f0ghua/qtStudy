#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"

#include "CDDDbGAPDATAOBJ.h"

namespace vector {
namespace cdd {

CDDDbGAPDATAOBJ::CDDDbGAPDATAOBJ()
{
}

CDDDbGAPDATAOBJ::~CDDDbGAPDATAOBJ()
{
}

void CDDDbGAPDATAOBJ::load(const QDomElement &element)
{
    CDDDbGAPDATAOBJImpl::load(element);
}

} // namespace cdd
} // namespace vector

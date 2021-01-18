#include "CDDDbDESC.h"
#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"

#include "CDDDbDATAOBJ.h"

namespace vector {
namespace cdd {

CDDDbDATAOBJ::CDDDbDATAOBJ()
{
}

CDDDbDATAOBJ::~CDDDbDATAOBJ()
{
}

void CDDDbDATAOBJ::load(const QDomElement &element)
{
    CDDDbDATAOBJImpl::load(element);
}

} // namespace cdd
} // namespace vector

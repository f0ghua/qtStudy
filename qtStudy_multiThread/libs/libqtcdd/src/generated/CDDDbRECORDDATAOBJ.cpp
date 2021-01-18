#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"
#include "CDDDbRECORDDT.h"

#include "CDDDbRECORDDATAOBJ.h"

namespace vector {
namespace cdd {

CDDDbRECORDDATAOBJ::CDDDbRECORDDATAOBJ()
{
}

CDDDbRECORDDATAOBJ::~CDDDbRECORDDATAOBJ()
{
}

void CDDDbRECORDDATAOBJ::load(const QDomElement &element)
{
    CDDDbRECORDDATAOBJImpl::load(element);
}

} // namespace cdd
} // namespace vector

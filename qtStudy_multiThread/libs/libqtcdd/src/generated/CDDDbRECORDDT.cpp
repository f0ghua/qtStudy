#include "CDDDbCVALUETYPE.h"
#include "CDDDbNAME.h"
#include "CDDDbPVALUETYPE.h"
#include "CDDDbQUAL.h"
#include "CDDDbRECORD.h"

#include "CDDDbRECORDDT.h"

namespace vector {
namespace cdd {

CDDDbRECORDDT::CDDDbRECORDDT()
{
}

CDDDbRECORDDT::~CDDDbRECORDDT()
{
}

void CDDDbRECORDDT::load(const QDomElement &element)
{
    CDDDbRECORDDTImpl::load(element);
}

} // namespace cdd
} // namespace vector

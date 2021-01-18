#include "CDDDbNAME.h"
#include "CDDDbNEGRESCODEPROXY.h"
#include "CDDDbQUAL.h"
#include "CDDDbSTATE.h"

#include "CDDDbSTATEGROUP.h"

namespace vector {
namespace cdd {

CDDDbSTATEGROUP::CDDDbSTATEGROUP()
{
}

CDDDbSTATEGROUP::~CDDDbSTATEGROUP()
{
}

void CDDDbSTATEGROUP::load(const QDomElement &element)
{
    CDDDbSTATEGROUPImpl::load(element);
}

} // namespace cdd
} // namespace vector

#include "CDDDbCVALUETYPE.h"
#include "CDDDbDESC.h"
#include "CDDDbENUM.h"
#include "CDDDbEXCL.h"
#include "CDDDbNAME.h"
#include "CDDDbPVALUETYPE.h"
#include "CDDDbQUAL.h"

#include "CDDDbIDENT.h"

namespace vector {
namespace cdd {

CDDDbIDENT::CDDDbIDENT()
{
}

CDDDbIDENT::~CDDDbIDENT()
{
}

void CDDDbIDENT::load(const QDomElement &element)
{
    CDDDbIDENTImpl::load(element);
}

} // namespace cdd
} // namespace vector

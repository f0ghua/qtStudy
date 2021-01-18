#include "CDDDbCVALUETYPE.h"
#include "CDDDbDATAOBJ.h"
#include "CDDDbGAPDATAOBJ.h"
#include "CDDDbNAME.h"
#include "CDDDbPVALUETYPE.h"
#include "CDDDbQUAL.h"
#include "CDDDbSTRUCT.h"

#include "CDDDbSTRUCTDT.h"

namespace vector {
namespace cdd {

CDDDbSTRUCTDT::CDDDbSTRUCTDT()
{
}

CDDDbSTRUCTDT::~CDDDbSTRUCTDT()
{
}

void CDDDbSTRUCTDT::load(const QDomElement &element)
{
    CDDDbSTRUCTDTImpl::load(element);
}

} // namespace cdd
} // namespace vector

#include "CDDDbDATAOBJ.h"
#include "CDDDbGAPDATAOBJ.h"
#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"

#include "CDDDbSTRUCT.h"

namespace vector {
namespace cdd {

CDDDbSTRUCT::CDDDbSTRUCT()
{
}

CDDDbSTRUCT::~CDDDbSTRUCT()
{
}

void CDDDbSTRUCT::load(const QDomElement &element)
{
    CDDDbSTRUCTImpl::load(element);
}

} // namespace cdd
} // namespace vector

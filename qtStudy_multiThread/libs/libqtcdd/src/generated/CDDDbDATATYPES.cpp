#include "CDDDbIDENT.h"
#include "CDDDbLINCOMP.h"
#include "CDDDbMUXDT.h"
#include "CDDDbSTRUCTDT.h"
#include "CDDDbTEXTTBL.h"

#include "CDDDbDATATYPES.h"

namespace vector {
namespace cdd {

CDDDbDATATYPES::CDDDbDATATYPES()
{
}

CDDDbDATATYPES::~CDDDbDATATYPES()
{
}

void CDDDbDATATYPES::load(const QDomElement &element)
{
    CDDDbDATATYPESImpl::load(element);
}

} // namespace cdd
} // namespace vector

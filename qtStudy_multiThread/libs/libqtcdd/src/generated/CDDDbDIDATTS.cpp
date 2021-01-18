#include "CDDDbCSTRDEF.h"
#include "CDDDbUNSDEF.h"

#include "CDDDbDIDATTS.h"

namespace vector {
namespace cdd {

CDDDbDIDATTS::CDDDbDIDATTS()
{
}

CDDDbDIDATTS::~CDDDbDIDATTS()
{
}

void CDDDbDIDATTS::load(const QDomElement &element)
{
    CDDDbDIDATTSImpl::load(element);
}

} // namespace cdd
} // namespace vector

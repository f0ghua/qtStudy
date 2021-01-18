#include "CDDDbCSTRDEF.h"
#include "CDDDbENUMDEF.h"
#include "CDDDbUNSDEF.h"

#include "CDDDbRECORDATTS.h"

namespace vector {
namespace cdd {

CDDDbRECORDATTS::CDDDbRECORDATTS()
{
}

CDDDbRECORDATTS::~CDDDbRECORDATTS()
{
}

void CDDDbRECORDATTS::load(const QDomElement &element)
{
    CDDDbRECORDATTSImpl::load(element);
}

} // namespace cdd
} // namespace vector

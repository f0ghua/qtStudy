#include "CDDDbCSTRDEF.h"

#include "CDDDbSTATEGROUPATTS.h"

namespace vector {
namespace cdd {

CDDDbSTATEGROUPATTS::CDDDbSTATEGROUPATTS()
{
}

CDDDbSTATEGROUPATTS::~CDDDbSTATEGROUPATTS()
{
}

void CDDDbSTATEGROUPATTS::load(const QDomElement &element)
{
    CDDDbSTATEGROUPATTSImpl::load(element);
}

} // namespace cdd
} // namespace vector

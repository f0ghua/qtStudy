#include "CDDDbCSTRDEF.h"
#include "CDDDbENUMDEF.h"

#include "CDDDbDATATYPEATTS.h"

namespace vector {
namespace cdd {

CDDDbDATATYPEATTS::CDDDbDATATYPEATTS()
{
}

CDDDbDATATYPEATTS::~CDDDbDATATYPEATTS()
{
}

void CDDDbDATATYPEATTS::load(const QDomElement &element)
{
    CDDDbDATATYPEATTSImpl::load(element);
}

} // namespace cdd
} // namespace vector

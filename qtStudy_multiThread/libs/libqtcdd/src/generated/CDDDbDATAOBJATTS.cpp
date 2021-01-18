#include "CDDDbCSTRDEF.h"
#include "CDDDbENUMDEF.h"
#include "CDDDbSTRDEF.h"

#include "CDDDbDATAOBJATTS.h"

namespace vector {
namespace cdd {

CDDDbDATAOBJATTS::CDDDbDATAOBJATTS()
{
}

CDDDbDATAOBJATTS::~CDDDbDATAOBJATTS()
{
}

void CDDDbDATAOBJATTS::load(const QDomElement &element)
{
    CDDDbDATAOBJATTSImpl::load(element);
}

} // namespace cdd
} // namespace vector

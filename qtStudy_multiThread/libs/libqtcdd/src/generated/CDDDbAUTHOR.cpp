#include "CDDDbCOMPANY.h"
#include "CDDDbFIRSTNAME.h"
#include "CDDDbLASTNAME.h"
#include "CDDDbSHORTNAME.h"

#include "CDDDbAUTHOR.h"

namespace vector {
namespace cdd {

CDDDbAUTHOR::CDDDbAUTHOR()
{
}

CDDDbAUTHOR::~CDDDbAUTHOR()
{
}

void CDDDbAUTHOR::load(const QDomElement &element)
{
    CDDDbAUTHORImpl::load(element);
}

} // namespace cdd
} // namespace vector

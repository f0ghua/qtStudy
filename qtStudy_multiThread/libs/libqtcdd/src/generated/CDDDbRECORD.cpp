#include "CDDDbCSTR.h"
#include "CDDDbENUM.h"
#include "CDDDbENUMRECORDITEM.h"
#include "CDDDbTEXT.h"
#include "CDDDbTRRECORDITEM.h"
#include "CDDDbUNS.h"
#include "CDDDbUNSRECORDITEM.h"

#include "CDDDbRECORD.h"

namespace vector {
namespace cdd {

CDDDbRECORD::CDDDbRECORD()
{
}

CDDDbRECORD::~CDDDbRECORD()
{
}

void CDDDbRECORD::load(const QDomElement &element)
{
    CDDDbRECORDImpl::load(element);
}

} // namespace cdd
} // namespace vector

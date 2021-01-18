#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"

#include "CDDDbCONSTCOMP.h"

namespace vector {
namespace cdd {

CDDDbCONSTCOMP::CDDDbCONSTCOMP()
{
}

CDDDbCONSTCOMP::~CDDDbCONSTCOMP()
{
}

void CDDDbCONSTCOMP::load(const QDomElement &element)
{
    CDDDbCONSTCOMPImpl::load(element);
}

} // namespace cdd
} // namespace vector

#include "CDDDbDESC.h"
#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"

#include "CDDDbATTRCAT.h"

namespace vector {
namespace cdd {

CDDDbATTRCAT::CDDDbATTRCAT()
{
}

CDDDbATTRCAT::~CDDDbATTRCAT()
{
}

void CDDDbATTRCAT::load(const QDomElement &element)
{
    CDDDbATTRCATImpl::load(element);
}

} // namespace cdd
} // namespace vector

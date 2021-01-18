#include "CDDDbDESC.h"
#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"
#include "CDDDbSTRING.h"

#include "CDDDbSTRDEF.h"

namespace vector {
namespace cdd {

CDDDbSTRDEF::CDDDbSTRDEF()
{
}

CDDDbSTRDEF::~CDDDbSTRDEF()
{
}

void CDDDbSTRDEF::load(const QDomElement &element)
{
    CDDDbSTRDEFImpl::load(element);
}

} // namespace cdd
} // namespace vector

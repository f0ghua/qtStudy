#include "CDDDbCOMMONSTRING.h"
#include "CDDDbDESC.h"
#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"

#include "CDDDbCSTRDEF.h"

namespace vector {
namespace cdd {

CDDDbCSTRDEF::CDDDbCSTRDEF()
{
}

CDDDbCSTRDEF::~CDDDbCSTRDEF()
{
}

void CDDDbCSTRDEF::load(const QDomElement &element)
{
    CDDDbCSTRDEFImpl::load(element);
}

} // namespace cdd
} // namespace vector

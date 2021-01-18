#include "CDDDbDESC.h"
#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"

#include "CDDDbUNSDEF.h"

namespace vector {
namespace cdd {

CDDDbUNSDEF::CDDDbUNSDEF()
{
}

CDDDbUNSDEF::~CDDDbUNSDEF()
{
}

void CDDDbUNSDEF::load(const QDomElement &element)
{
    CDDDbUNSDEFImpl::load(element);
}

} // namespace cdd
} // namespace vector

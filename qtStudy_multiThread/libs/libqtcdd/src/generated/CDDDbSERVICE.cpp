#include "CDDDbENUM.h"
#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"
#include "CDDDbSHORTCUTNAME.h"
#include "CDDDbSHORTCUTQUAL.h"

#include "CDDDbSERVICE.h"

namespace vector {
namespace cdd {

CDDDbSERVICE::CDDDbSERVICE()
{
}

CDDDbSERVICE::~CDDDbSERVICE()
{
}

void CDDDbSERVICE::load(const QDomElement &element)
{
    CDDDbSERVICEImpl::load(element);
}

} // namespace cdd
} // namespace vector

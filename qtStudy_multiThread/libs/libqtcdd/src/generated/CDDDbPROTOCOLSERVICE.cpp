#include "CDDDbDESC.h"
#include "CDDDbNAME.h"
#include "CDDDbNEG.h"
#include "CDDDbNEGRESCODEPROXIES.h"
#include "CDDDbPOS.h"
#include "CDDDbQUAL.h"
#include "CDDDbREQ.h"

#include "CDDDbPROTOCOLSERVICE.h"

namespace vector {
namespace cdd {

CDDDbPROTOCOLSERVICE::CDDDbPROTOCOLSERVICE()
{
}

CDDDbPROTOCOLSERVICE::~CDDDbPROTOCOLSERVICE()
{
}

void CDDDbPROTOCOLSERVICE::load(const QDomElement &element)
{
    CDDDbPROTOCOLSERVICEImpl::load(element);
}

} // namespace cdd
} // namespace vector

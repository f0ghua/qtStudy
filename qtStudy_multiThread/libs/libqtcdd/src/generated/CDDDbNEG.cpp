#include "CDDDbCONSTCOMP.h"
#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"
#include "CDDDbSIMPLEPROXYCOMP.h"

#include "CDDDbNEG.h"

namespace vector {
namespace cdd {

CDDDbNEG::CDDDbNEG()
{
}

CDDDbNEG::~CDDDbNEG()
{
}

void CDDDbNEG::load(const QDomElement &element)
{
    CDDDbNEGImpl::load(element);
}

} // namespace cdd
} // namespace vector

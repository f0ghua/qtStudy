
#include "CDDDbNEGRESCODEPROXYImpl.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbNEGRESCODEPROXYImpl::CDDDbNEGRESCODEPROXYImpl()
{
}

CDDDbNEGRESCODEPROXYImpl::~CDDDbNEGRESCODEPROXYImpl()
{
}

void CDDDbNEGRESCODEPROXYImpl::load(const QDomElement &element)
{
    m_idref = element.attribute("idref");

}

} // namespace cdd
} // namespace vector

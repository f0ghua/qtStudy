
#include "CDDDbNEGRESCODEPROXY.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbNEGRESCODEPROXY::CDDDbNEGRESCODEPROXY()
{
}

CDDDbNEGRESCODEPROXY::~CDDDbNEGRESCODEPROXY()
{
}

void CDDDbNEGRESCODEPROXY::load(const QDomElement &element)
{
    m_idref = element.attribute("idref");

}

} // namespace cdd
} // namespace vector

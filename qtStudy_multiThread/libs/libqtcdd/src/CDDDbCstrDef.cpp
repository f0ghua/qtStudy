#include "CDDLog.h"
#include "CDDDbCstrDef.h"
#include "CDDDbTuv.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbCstrDef::CDDDbCstrDef()
    : CDDDbNamedElementType()
    , CDDDbAttrCatRefType()
{
}

CDDDbCstrDef::~CDDDbCstrDef()
{

}

void CDDDbCstrDef::load(const QDomElement &element)
{
    CDDDbNamedElementType::load(element);
    CDDDbAttrCatRefType::load(element);
}

} // namespace cdd
} // namespace vector

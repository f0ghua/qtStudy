#include "CDDDbDesc.h"
#include "CDDDbName.h"
#include "CDDDbQual.h"
#include "CDDLog.h"

#include "CDDDbAttrCat.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbAttrCat::CDDDbAttrCat()
    : CDDDbNamedElementType()
{
}

CDDDbAttrCat::~CDDDbAttrCat()
{

}

void CDDDbAttrCat::load(const QDomElement &element)
{
    CDDDbNamedElementType::load(element);
}

} // namespace cdd
} // namespace vector

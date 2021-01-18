
#include "CDDDbREASON.h"

namespace vector {
namespace cdd {

CDDDbREASON::CDDDbREASON()
{
}

CDDDbREASON::~CDDDbREASON()
{
}

void CDDDbREASON::load(const QDomElement &element)
{
    CDDDbREASONImpl::load(element);
}

} // namespace cdd
} // namespace vector

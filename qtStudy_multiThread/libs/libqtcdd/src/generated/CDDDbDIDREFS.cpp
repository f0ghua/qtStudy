#include "CDDDbDIDREF.h"

#include "CDDDbDIDREFS.h"

namespace vector {
namespace cdd {

CDDDbDIDREFS::CDDDbDIDREFS()
{
}

CDDDbDIDREFS::~CDDDbDIDREFS()
{
}

void CDDDbDIDREFS::load(const QDomElement &element)
{
    CDDDbDIDREFSImpl::load(element);
}

} // namespace cdd
} // namespace vector

#include "CDDDbDESC.h"
#include "CDDDbETAG.h"
#include "CDDDbNAME.h"
#include "CDDDbQUAL.h"

#include "CDDDbENUMDEF.h"

namespace vector {
namespace cdd {

CDDDbENUMDEF::CDDDbENUMDEF()
{
}

CDDDbENUMDEF::~CDDDbENUMDEF()
{
}

void CDDDbENUMDEF::load(const QDomElement &element)
{
    CDDDbENUMDEFImpl::load(element);

    for (const auto &e : m_elEtags) {
        if (!e.isNull()) {
            m_elEtagsCtr.insert(e->m_v, e->getValue());
        }
    }
}

} // namespace cdd
} // namespace vector

#ifndef VECTOR_CDD_CDDDBSHORTCUTNAME_H
#define VECTOR_CDD_CDDDBSHORTCUTNAME_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbTUV;

/**
 * @brief element SHORTCUTNAME
 *
 */
class VECTOR_CDD_API CDDDbSHORTCUTNAME
{
public:
    CDDDbSHORTCUTNAME();
    ~CDDDbSHORTCUTNAME();

    void load(const QDomElement &element);

    /** @element TUV */
    QSharedPointer<CDDDbTUV> m_tuv;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSHORTCUTNAME_H

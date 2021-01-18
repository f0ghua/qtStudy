#ifndef VECTOR_CDD_CDDDBPROXYCOMPREFIMPL_H
#define VECTOR_CDD_CDDDBPROXYCOMPREFIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {


/**
 * @brief element PROXYCOMPREF
 *
 */
class VECTOR_CDD_API CDDDbPROXYCOMPREFImpl
{
public:
    CDDDbPROXYCOMPREFImpl();
    ~CDDDbPROXYCOMPREFImpl();

    void load(const QDomElement &element);

    /** @attribute idref */
    QString m_idref;

    QString m_text;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBPROXYCOMPREFIMPL_H

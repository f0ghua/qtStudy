#ifndef VECTOR_CDD_CDDDBPROXYCOMPREF_H
#define VECTOR_CDD_CDDDBPROXYCOMPREF_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {


/**
 * @brief element PROXYCOMPREF
 *
 */
class VECTOR_CDD_API CDDDbPROXYCOMPREF
{
public:
    CDDDbPROXYCOMPREF();
    ~CDDDbPROXYCOMPREF();

    void load(const QDomElement &element);

    /** @attribute idref */
    QString m_idref;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBPROXYCOMPREF_H

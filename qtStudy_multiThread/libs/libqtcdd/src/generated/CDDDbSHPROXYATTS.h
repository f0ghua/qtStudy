#ifndef VECTOR_CDD_CDDDBSHPROXYATTS_H
#define VECTOR_CDD_CDDDBSHPROXYATTS_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbCSTRDEF;
class CDDDbSTRDEF;

/**
 * @brief element SHPROXYATTS
 *
 */
class VECTOR_CDD_API CDDDbSHPROXYATTS
{
public:
    CDDDbSHPROXYATTS();
    ~CDDDbSHPROXYATTS();

    void load(const QDomElement &element);

    /** @element CSTRDEF */
    QSharedPointer<CDDDbCSTRDEF> m_cstrdef;

    /** @element STRDEF */
    QSharedPointer<CDDDbSTRDEF> m_strdef;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSHPROXYATTS_H

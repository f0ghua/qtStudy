#ifndef VECTOR_CDD_CDDDBSHPROXYATTSIMPL_H
#define VECTOR_CDD_CDDDBSHPROXYATTSIMPL_H

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
class VECTOR_CDD_API CDDDbSHPROXYATTSImpl
{
public:
    CDDDbSHPROXYATTSImpl();
    ~CDDDbSHPROXYATTSImpl();

    void load(const QDomElement &element);

    QString m_text;

    /** @element CSTRDEF */
    QMap<QString, QSharedPointer<CDDDbCSTRDEF>> m_elCstrdefs;

    /** @element STRDEF */
    QMap<QString, QSharedPointer<CDDDbSTRDEF>> m_elStrdefs;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSHPROXYATTSIMPL_H

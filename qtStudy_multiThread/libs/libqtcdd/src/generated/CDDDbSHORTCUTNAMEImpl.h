#ifndef VECTOR_CDD_CDDDBSHORTCUTNAMEIMPL_H
#define VECTOR_CDD_CDDDBSHORTCUTNAMEIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbTUV;

/**
 * @brief element SHORTCUTNAME
 *
 */
class VECTOR_CDD_API CDDDbSHORTCUTNAMEImpl
{
public:
    CDDDbSHORTCUTNAMEImpl();
    ~CDDDbSHORTCUTNAMEImpl();

    void load(const QDomElement &element);

    QString m_text;

    /** @element TUV */
    QVector<QSharedPointer<CDDDbTUV>> m_elTuvs;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSHORTCUTNAMEIMPL_H

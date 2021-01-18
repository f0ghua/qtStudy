#ifndef VECTOR_CDD_CDDDBDEFAULTIMPL_H
#define VECTOR_CDD_CDDDBDEFAULTIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbTUV;

/**
 * @brief element DEFAULT
 *
 */
class VECTOR_CDD_API CDDDbDEFAULTImpl
{
public:
    CDDDbDEFAULTImpl();
    ~CDDDbDEFAULTImpl();

    void load(const QDomElement &element);

    QString m_text;

    /** @element TUV */
    QVector<QSharedPointer<CDDDbTUV>> m_elTuvs;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDEFAULTIMPL_H

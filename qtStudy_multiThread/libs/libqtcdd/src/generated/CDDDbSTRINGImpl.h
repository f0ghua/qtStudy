#ifndef VECTOR_CDD_CDDDBSTRINGIMPL_H
#define VECTOR_CDD_CDDDBSTRINGIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbTUV;

/**
 * @brief element STRING
 *
 */
class VECTOR_CDD_API CDDDbSTRINGImpl
{
public:
    CDDDbSTRINGImpl();
    ~CDDDbSTRINGImpl();

    void load(const QDomElement &element);

    QString m_text;

    /** @element TUV */
    QVector<QSharedPointer<CDDDbTUV>> m_elTuvs;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSTRINGIMPL_H

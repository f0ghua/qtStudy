#ifndef VECTOR_CDD_CDDDBTEXTIMPL_H
#define VECTOR_CDD_CDDDBTEXTIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbTUV;

/**
 * @brief element TEXT
 *
 */
class VECTOR_CDD_API CDDDbTEXTImpl
{
public:
    CDDDbTEXTImpl();
    ~CDDDbTEXTImpl();

    void load(const QDomElement &element);

    QString m_text;

    /** @element TUV */
    QVector<QSharedPointer<CDDDbTUV>> m_elTuvs;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBTEXTIMPL_H

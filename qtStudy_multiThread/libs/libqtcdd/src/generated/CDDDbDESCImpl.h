#ifndef VECTOR_CDD_CDDDBDESCIMPL_H
#define VECTOR_CDD_CDDDBDESCIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbTUV;

/**
 * @brief element DESC
 *
 */
class VECTOR_CDD_API CDDDbDESCImpl
{
public:
    CDDDbDESCImpl();
    ~CDDDbDESCImpl();

    void load(const QDomElement &element);

    QString m_text;

    /** @element TUV */
    QVector<QSharedPointer<CDDDbTUV>> m_elTuvs;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDESCIMPL_H

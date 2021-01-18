#ifndef VECTOR_CDD_CDDDBNAMEIMPL_H
#define VECTOR_CDD_CDDDBNAMEIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbTUV;

/**
 * @brief element NAME
 *
 */
class VECTOR_CDD_API CDDDbNAMEImpl
{
public:
    CDDDbNAMEImpl();
    ~CDDDbNAMEImpl();

    void load(const QDomElement &element);

    QString m_text;

    /** @element TUV */
    QMap<QString, QSharedPointer<CDDDbTUV>> m_elTuvs;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBNAMEIMPL_H

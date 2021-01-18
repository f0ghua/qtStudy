#ifndef VECTOR_CDD_CDDDBPARAIMPL_H
#define VECTOR_CDD_CDDDBPARAIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbFC;

/**
 * @brief element PARA
 *
 */
class VECTOR_CDD_API CDDDbPARAImpl
{
public:
    CDDDbPARAImpl();
    ~CDDDbPARAImpl();

    void load(const QDomElement &element);

    /** @attribute list */
    QString m_list;

    QString m_text;

    /** @element FC */
    QVector<QSharedPointer<CDDDbFC>> m_elFcs;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBPARAIMPL_H

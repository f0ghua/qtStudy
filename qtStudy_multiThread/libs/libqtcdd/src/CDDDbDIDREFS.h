#ifndef VECTOR_CDD_CDDDBDIDREFS_H
#define VECTOR_CDD_CDDDBDIDREFS_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbDIDREF;

/**
 * @brief element DIDREFS
 *
 */
class VECTOR_CDD_API CDDDbDIDREFS
{
public:
    CDDDbDIDREFS();
    ~CDDDbDIDREFS();

    void load(const QDomElement &element);

    /** @element DIDREF */
    QVector<QSharedPointer<CDDDbDIDREF>> m_didrefs;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDIDREFS_H

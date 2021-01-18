#ifndef VECTOR_CDD_CDDDBDIDREFSIMPL_H
#define VECTOR_CDD_CDDDBDIDREFSIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbDIDREF;

/**
 * @brief element DIDREFS
 *
 */
class VECTOR_CDD_API CDDDbDIDREFSImpl
{
public:
    CDDDbDIDREFSImpl();
    ~CDDDbDIDREFSImpl();

    void load(const QDomElement &element);

    QString m_text;

    /** @element DIDREF */
    QVector<QSharedPointer<CDDDbDIDREF>> m_elDidrefs;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDIDREFSIMPL_H

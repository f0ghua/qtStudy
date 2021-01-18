#ifndef VECTOR_CDD_CDDDBDIDSIMPL_H
#define VECTOR_CDD_CDDDBDIDSIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbDID;

/**
 * @brief element DIDS
 *
 */
class VECTOR_CDD_API CDDDbDIDSImpl
{
public:
    CDDDbDIDSImpl();
    ~CDDDbDIDSImpl();

    void load(const QDomElement &element);

    QString m_text;

    /** @element DID */
    QMap<QString, QSharedPointer<CDDDbDID>> m_elDids;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDIDSIMPL_H

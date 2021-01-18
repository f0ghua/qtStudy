#ifndef VECTOR_CDD_CDDDBSTRUCTUREIMPL_H
#define VECTOR_CDD_CDDDBSTRUCTUREIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbDATAOBJ;

/**
 * @brief element STRUCTURE
 *
 */
class VECTOR_CDD_API CDDDbSTRUCTUREImpl
{
public:
    CDDDbSTRUCTUREImpl();
    ~CDDDbSTRUCTUREImpl();

    void load(const QDomElement &element);

    QString m_text;

    /** @element DATAOBJ */
    QMap<QString, QSharedPointer<CDDDbDATAOBJ>> m_elDataobjs;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSTRUCTUREIMPL_H

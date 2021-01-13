#ifndef VECTOR_CDD_CDDDBSTRUCTURE_H
#define VECTOR_CDD_CDDDBSTRUCTURE_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbDATAOBJ;

/**
 * @brief element STRUCTURE
 *
 */
class VECTOR_CDD_API CDDDbSTRUCTURE
{
public:
    CDDDbSTRUCTURE();
    ~CDDDbSTRUCTURE();

    void load(const QDomElement &element);

    /** @element DATAOBJ */
    QVector<QSharedPointer<CDDDbDATAOBJ>> m_dataobjs;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSTRUCTURE_H

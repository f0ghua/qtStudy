#ifndef VECTOR_CDD_CDDDBPARA_H
#define VECTOR_CDD_CDDDBPARA_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbFC;

/**
 * @brief element PARA
 *
 */
class VECTOR_CDD_API CDDDbPARA
{
public:
    CDDDbPARA();
    ~CDDDbPARA();

    void load(const QDomElement &element);

    /** @element FC */
    QSharedPointer<CDDDbFC> m_fc;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBPARA_H

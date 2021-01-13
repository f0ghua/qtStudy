#ifndef VECTOR_CDD_CDDDBJOBCNRATTS_H
#define VECTOR_CDD_CDDDBJOBCNRATTS_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbENUMDEF;

/**
 * @brief element JOBCNRATTS
 *
 */
class VECTOR_CDD_API CDDDbJOBCNRATTS
{
public:
    CDDDbJOBCNRATTS();
    ~CDDDbJOBCNRATTS();

    void load(const QDomElement &element);

    /** @element ENUMDEF */
    QSharedPointer<CDDDbENUMDEF> m_enumdef;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBJOBCNRATTS_H

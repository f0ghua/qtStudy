#ifndef VECTOR_CDD_CDDDBJOBATTS_H
#define VECTOR_CDD_CDDDBJOBATTS_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbENUMDEF;

/**
 * @brief element JOBATTS
 *
 */
class VECTOR_CDD_API CDDDbJOBATTS
{
public:
    CDDDbJOBATTS();
    ~CDDDbJOBATTS();

    void load(const QDomElement &element);

    /** @element ENUMDEF */
    QSharedPointer<CDDDbENUMDEF> m_enumdef;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBJOBATTS_H

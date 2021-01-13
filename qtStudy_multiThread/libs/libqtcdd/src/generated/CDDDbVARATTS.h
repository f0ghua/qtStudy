#ifndef VECTOR_CDD_CDDDBVARATTS_H
#define VECTOR_CDD_CDDDBVARATTS_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbENUMDEF;

/**
 * @brief element VARATTS
 *
 */
class VECTOR_CDD_API CDDDbVARATTS
{
public:
    CDDDbVARATTS();
    ~CDDDbVARATTS();

    void load(const QDomElement &element);

    /** @element ENUMDEF */
    QSharedPointer<CDDDbENUMDEF> m_enumdef;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBVARATTS_H

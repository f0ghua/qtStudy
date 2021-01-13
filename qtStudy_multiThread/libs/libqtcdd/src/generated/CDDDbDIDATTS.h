#ifndef VECTOR_CDD_CDDDBDIDATTS_H
#define VECTOR_CDD_CDDDBDIDATTS_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbCSTRDEF;
class CDDDbUNSDEF;

/**
 * @brief element DIDATTS
 *
 */
class VECTOR_CDD_API CDDDbDIDATTS
{
public:
    CDDDbDIDATTS();
    ~CDDDbDIDATTS();

    void load(const QDomElement &element);

    /** @element CSTRDEF */
    QSharedPointer<CDDDbCSTRDEF> m_cstrdef;

    /** @element UNSDEF */
    QSharedPointer<CDDDbUNSDEF> m_unsdef;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDIDATTS_H

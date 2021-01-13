#ifndef VECTOR_CDD_CDDDBECUATTS_H
#define VECTOR_CDD_CDDDBECUATTS_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbCSTRDEF;
class CDDDbENUMDEF;
class CDDDbSTRDEF;
class CDDDbUNSDEF;

/**
 * @brief element ECUATTS
 *
 */
class VECTOR_CDD_API CDDDbECUATTS
{
public:
    CDDDbECUATTS();
    ~CDDDbECUATTS();

    void load(const QDomElement &element);

    /** @element CSTRDEF */
    QMap<QString, QSharedPointer<CDDDbCSTRDEF>> m_cstrdefs;

    /** @element ENUMDEF */
    QMap<QString, QSharedPointer<CDDDbENUMDEF>> m_enumdefs;

    /** @element STRDEF */
    QSharedPointer<CDDDbSTRDEF> m_strdef;

    /** @element UNSDEF */
    QMap<QString, QSharedPointer<CDDDbUNSDEF>> m_unsdefs;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBECUATTS_H

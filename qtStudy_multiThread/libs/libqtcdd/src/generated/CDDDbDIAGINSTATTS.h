#ifndef VECTOR_CDD_CDDDBDIAGINSTATTS_H
#define VECTOR_CDD_CDDDBDIAGINSTATTS_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbCSTRDEF;
class CDDDbENUMDEF;
class CDDDbUNSDEF;

/**
 * @brief element DIAGINSTATTS
 *
 */
class VECTOR_CDD_API CDDDbDIAGINSTATTS
{
public:
    CDDDbDIAGINSTATTS();
    ~CDDDbDIAGINSTATTS();

    void load(const QDomElement &element);

    /** @element CSTRDEF */
    QMap<QString, QSharedPointer<CDDDbCSTRDEF>> m_cstrdefs;

    /** @element ENUMDEF */
    QMap<QString, QSharedPointer<CDDDbENUMDEF>> m_enumdefs;

    /** @element UNSDEF */
    QMap<QString, QSharedPointer<CDDDbUNSDEF>> m_unsdefs;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDIAGINSTATTS_H

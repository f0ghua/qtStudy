#ifndef VECTOR_CDD_CDDDBECUATTSIMPL_H
#define VECTOR_CDD_CDDDBECUATTSIMPL_H

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
class VECTOR_CDD_API CDDDbECUATTSImpl
{
public:
    CDDDbECUATTSImpl();
    ~CDDDbECUATTSImpl();

    void load(const QDomElement &element);

    QString m_text;

    /** @element CSTRDEF */
    QMap<QString, QSharedPointer<CDDDbCSTRDEF>> m_elCstrdefs;

    /** @element ENUMDEF */
    QMap<QString, QSharedPointer<CDDDbENUMDEF>> m_elEnumdefs;

    /** @element STRDEF */
    QMap<QString, QSharedPointer<CDDDbSTRDEF>> m_elStrdefs;

    /** @element UNSDEF */
    QMap<QString, QSharedPointer<CDDDbUNSDEF>> m_elUnsdefs;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBECUATTSIMPL_H

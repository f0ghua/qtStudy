#ifndef VECTOR_CDD_CDDDBDIDATTSIMPL_H
#define VECTOR_CDD_CDDDBDIDATTSIMPL_H

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
class VECTOR_CDD_API CDDDbDIDATTSImpl
{
public:
    CDDDbDIDATTSImpl();
    ~CDDDbDIDATTSImpl();

    void load(const QDomElement &element);

    QString m_text;

    /** @element CSTRDEF */
    QMap<QString, QSharedPointer<CDDDbCSTRDEF>> m_elCstrdefs;

    /** @element UNSDEF */
    QMap<QString, QSharedPointer<CDDDbUNSDEF>> m_elUnsdefs;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDIDATTSIMPL_H

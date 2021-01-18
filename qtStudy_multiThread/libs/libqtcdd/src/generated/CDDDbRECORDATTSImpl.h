#ifndef VECTOR_CDD_CDDDBRECORDATTSIMPL_H
#define VECTOR_CDD_CDDDBRECORDATTSIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbCSTRDEF;
class CDDDbENUMDEF;
class CDDDbUNSDEF;

/**
 * @brief element RECORDATTS
 *
 */
class VECTOR_CDD_API CDDDbRECORDATTSImpl
{
public:
    CDDDbRECORDATTSImpl();
    ~CDDDbRECORDATTSImpl();

    void load(const QDomElement &element);

    QString m_text;

    /** @element CSTRDEF */
    QMap<QString, QSharedPointer<CDDDbCSTRDEF>> m_elCstrdefs;

    /** @element ENUMDEF */
    QMap<QString, QSharedPointer<CDDDbENUMDEF>> m_elEnumdefs;

    /** @element UNSDEF */
    QMap<QString, QSharedPointer<CDDDbUNSDEF>> m_elUnsdefs;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBRECORDATTSIMPL_H

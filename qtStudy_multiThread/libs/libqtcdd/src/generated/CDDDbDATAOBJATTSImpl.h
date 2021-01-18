#ifndef VECTOR_CDD_CDDDBDATAOBJATTSIMPL_H
#define VECTOR_CDD_CDDDBDATAOBJATTSIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbCSTRDEF;
class CDDDbENUMDEF;
class CDDDbSTRDEF;

/**
 * @brief element DATAOBJATTS
 *
 */
class VECTOR_CDD_API CDDDbDATAOBJATTSImpl
{
public:
    CDDDbDATAOBJATTSImpl();
    ~CDDDbDATAOBJATTSImpl();

    void load(const QDomElement &element);

    QString m_text;

    /** @element CSTRDEF */
    QMap<QString, QSharedPointer<CDDDbCSTRDEF>> m_elCstrdefs;

    /** @element ENUMDEF */
    QMap<QString, QSharedPointer<CDDDbENUMDEF>> m_elEnumdefs;

    /** @element STRDEF */
    QMap<QString, QSharedPointer<CDDDbSTRDEF>> m_elStrdefs;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDATAOBJATTSIMPL_H

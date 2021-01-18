#ifndef VECTOR_CDD_CDDDBDATATYPEATTSIMPL_H
#define VECTOR_CDD_CDDDBDATATYPEATTSIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbCSTRDEF;
class CDDDbENUMDEF;

/**
 * @brief element DATATYPEATTS
 *
 */
class VECTOR_CDD_API CDDDbDATATYPEATTSImpl
{
public:
    CDDDbDATATYPEATTSImpl();
    ~CDDDbDATATYPEATTSImpl();

    void load(const QDomElement &element);

    QString m_text;

    /** @element CSTRDEF */
    QMap<QString, QSharedPointer<CDDDbCSTRDEF>> m_elCstrdefs;

    /** @element ENUMDEF */
    QMap<QString, QSharedPointer<CDDDbENUMDEF>> m_elEnumdefs;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDATATYPEATTSIMPL_H

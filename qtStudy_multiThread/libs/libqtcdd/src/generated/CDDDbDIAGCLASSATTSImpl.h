#ifndef VECTOR_CDD_CDDDBDIAGCLASSATTSIMPL_H
#define VECTOR_CDD_CDDDBDIAGCLASSATTSIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbENUMDEF;

/**
 * @brief element DIAGCLASSATTS
 *
 */
class VECTOR_CDD_API CDDDbDIAGCLASSATTSImpl
{
public:
    CDDDbDIAGCLASSATTSImpl();
    ~CDDDbDIAGCLASSATTSImpl();

    void load(const QDomElement &element);

    QString m_text;

    /** @element ENUMDEF */
    QMap<QString, QSharedPointer<CDDDbENUMDEF>> m_elEnumdefs;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDIAGCLASSATTSIMPL_H

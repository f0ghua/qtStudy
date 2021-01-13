#ifndef VECTOR_CDD_CDDDBDIAGCLASSATTS_H
#define VECTOR_CDD_CDDDBDIAGCLASSATTS_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbENUMDEF;

/**
 * @brief element DIAGCLASSATTS
 *
 */
class VECTOR_CDD_API CDDDbDIAGCLASSATTS
{
public:
    CDDDbDIAGCLASSATTS();
    ~CDDDbDIAGCLASSATTS();

    void load(const QDomElement &element);

    /** @element ENUMDEF */
    QMap<QString, QSharedPointer<CDDDbENUMDEF>> m_enumdefs;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDIAGCLASSATTS_H

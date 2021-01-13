#ifndef VECTOR_CDD_CDDDBDATATYPEATTS_H
#define VECTOR_CDD_CDDDBDATATYPEATTS_H

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
class VECTOR_CDD_API CDDDbDATATYPEATTS
{
public:
    CDDDbDATATYPEATTS();
    ~CDDDbDATATYPEATTS();

    void load(const QDomElement &element);

    /** @element CSTRDEF */
    QMap<QString, QSharedPointer<CDDDbCSTRDEF>> m_cstrdefs;

    /** @element ENUMDEF */
    QMap<QString, QSharedPointer<CDDDbENUMDEF>> m_enumdefs;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDATATYPEATTS_H

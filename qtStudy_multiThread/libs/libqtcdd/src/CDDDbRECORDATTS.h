#ifndef VECTOR_CDD_CDDDBRECORDATTS_H
#define VECTOR_CDD_CDDDBRECORDATTS_H

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
class VECTOR_CDD_API CDDDbRECORDATTS
{
public:
    CDDDbRECORDATTS();
    ~CDDDbRECORDATTS();

    void load(const QDomElement &element);

    /** @element CSTRDEF */
    QMap<QString, QSharedPointer<CDDDbCSTRDEF>> m_cstrdefs;

    /** @element ENUMDEF */
    QSharedPointer<CDDDbENUMDEF> m_enumdef;

    /** @element UNSDEF */
    QSharedPointer<CDDDbUNSDEF> m_unsdef;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBRECORDATTS_H

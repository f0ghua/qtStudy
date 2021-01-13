#ifndef VECTOR_CDD_CDDDBDATAOBJATTS_H
#define VECTOR_CDD_CDDDBDATAOBJATTS_H

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
class VECTOR_CDD_API CDDDbDATAOBJATTS
{
public:
    CDDDbDATAOBJATTS();
    ~CDDDbDATAOBJATTS();

    void load(const QDomElement &element);

    /** @element CSTRDEF */
    QMap<QString, QSharedPointer<CDDDbCSTRDEF>> m_cstrdefs;

    /** @element ENUMDEF */
    QSharedPointer<CDDDbENUMDEF> m_enumdef;

    /** @element STRDEF */
    QSharedPointer<CDDDbSTRDEF> m_strdef;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDATAOBJATTS_H

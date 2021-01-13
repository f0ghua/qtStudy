#ifndef VECTOR_CDD_CDDDBSERVICEATTS_H
#define VECTOR_CDD_CDDDBSERVICEATTS_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbENUMDEF;
class CDDDbSGNDEF;
class CDDDbSTRDEF;

/**
 * @brief element SERVICEATTS
 *
 */
class VECTOR_CDD_API CDDDbSERVICEATTS
{
public:
    CDDDbSERVICEATTS();
    ~CDDDbSERVICEATTS();

    void load(const QDomElement &element);

    /** @element ENUMDEF */
    QMap<QString, QSharedPointer<CDDDbENUMDEF>> m_enumdefs;

    /** @element SGNDEF */
    QSharedPointer<CDDDbSGNDEF> m_sgndef;

    /** @element STRDEF */
    QMap<QString, QSharedPointer<CDDDbSTRDEF>> m_strdefs;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSERVICEATTS_H

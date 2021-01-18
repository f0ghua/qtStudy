#ifndef VECTOR_CDD_CDDDBSERVICEATTSIMPL_H
#define VECTOR_CDD_CDDDBSERVICEATTSIMPL_H

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
class VECTOR_CDD_API CDDDbSERVICEATTSImpl
{
public:
    CDDDbSERVICEATTSImpl();
    ~CDDDbSERVICEATTSImpl();

    void load(const QDomElement &element);

    QString m_text;

    /** @element ENUMDEF */
    QMap<QString, QSharedPointer<CDDDbENUMDEF>> m_elEnumdefs;

    /** @element SGNDEF */
    QSharedPointer<CDDDbSGNDEF> m_elSgndef;

    /** @element STRDEF */
    QMap<QString, QSharedPointer<CDDDbSTRDEF>> m_elStrdefs;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSERVICEATTSIMPL_H

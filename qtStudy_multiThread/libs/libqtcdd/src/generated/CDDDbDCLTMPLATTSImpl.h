#ifndef VECTOR_CDD_CDDDBDCLTMPLATTSIMPL_H
#define VECTOR_CDD_CDDDBDCLTMPLATTSIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbCSTRDEF;
class CDDDbENUMDEF;
class CDDDbSTRDEF;

/**
 * @brief element DCLTMPLATTS
 *
 */
class VECTOR_CDD_API CDDDbDCLTMPLATTSImpl
{
public:
    CDDDbDCLTMPLATTSImpl();
    ~CDDDbDCLTMPLATTSImpl();

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

#endif // VECTOR_CDD_CDDDBDCLTMPLATTSIMPL_H

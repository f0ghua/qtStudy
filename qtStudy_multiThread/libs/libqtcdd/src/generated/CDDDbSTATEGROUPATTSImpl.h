#ifndef VECTOR_CDD_CDDDBSTATEGROUPATTSIMPL_H
#define VECTOR_CDD_CDDDBSTATEGROUPATTSIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbCSTRDEF;

/**
 * @brief element STATEGROUPATTS
 *
 */
class VECTOR_CDD_API CDDDbSTATEGROUPATTSImpl
{
public:
    CDDDbSTATEGROUPATTSImpl();
    ~CDDDbSTATEGROUPATTSImpl();

    void load(const QDomElement &element);

    QString m_text;

    /** @element CSTRDEF */
    QMap<QString, QSharedPointer<CDDDbCSTRDEF>> m_elCstrdefs;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSTATEGROUPATTSIMPL_H

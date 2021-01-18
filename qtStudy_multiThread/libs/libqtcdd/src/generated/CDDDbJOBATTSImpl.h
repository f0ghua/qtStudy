#ifndef VECTOR_CDD_CDDDBJOBATTSIMPL_H
#define VECTOR_CDD_CDDDBJOBATTSIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbENUMDEF;

/**
 * @brief element JOBATTS
 *
 */
class VECTOR_CDD_API CDDDbJOBATTSImpl
{
public:
    CDDDbJOBATTSImpl();
    ~CDDDbJOBATTSImpl();

    void load(const QDomElement &element);

    QString m_text;

    /** @element ENUMDEF */
    QMap<QString, QSharedPointer<CDDDbENUMDEF>> m_elEnumdefs;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBJOBATTSIMPL_H

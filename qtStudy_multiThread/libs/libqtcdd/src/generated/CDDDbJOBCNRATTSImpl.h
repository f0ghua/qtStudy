#ifndef VECTOR_CDD_CDDDBJOBCNRATTSIMPL_H
#define VECTOR_CDD_CDDDBJOBCNRATTSIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbENUMDEF;

/**
 * @brief element JOBCNRATTS
 *
 */
class VECTOR_CDD_API CDDDbJOBCNRATTSImpl
{
public:
    CDDDbJOBCNRATTSImpl();
    ~CDDDbJOBCNRATTSImpl();

    void load(const QDomElement &element);

    QString m_text;

    /** @element ENUMDEF */
    QMap<QString, QSharedPointer<CDDDbENUMDEF>> m_elEnumdefs;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBJOBCNRATTSIMPL_H

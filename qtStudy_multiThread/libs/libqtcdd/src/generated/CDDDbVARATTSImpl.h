#ifndef VECTOR_CDD_CDDDBVARATTSIMPL_H
#define VECTOR_CDD_CDDDBVARATTSIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbENUMDEF;

/**
 * @brief element VARATTS
 *
 */
class VECTOR_CDD_API CDDDbVARATTSImpl
{
public:
    CDDDbVARATTSImpl();
    ~CDDDbVARATTSImpl();

    void load(const QDomElement &element);

    QString m_text;

    /** @element ENUMDEF */
    QMap<QString, QSharedPointer<CDDDbENUMDEF>> m_elEnumdefs;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBVARATTSIMPL_H

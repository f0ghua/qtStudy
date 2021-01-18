#ifndef VECTOR_CDD_CDDDBQUALGENOPTIONSIMPL_H
#define VECTOR_CDD_CDDDBQUALGENOPTIONSIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {


/**
 * @brief element QUALGENOPTIONS
 *
 */
class VECTOR_CDD_API CDDDbQUALGENOPTIONSImpl
{
public:
    CDDDbQUALGENOPTIONSImpl();
    ~CDDDbQUALGENOPTIONSImpl();

    void load(const QDomElement &element);

    /** @attribute case */
    QString m_case;

    /** @attribute maxLen */
    QString m_maxLen;

    /** @attribute minLen */
    QString m_minLen;

    QString m_text;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBQUALGENOPTIONSIMPL_H

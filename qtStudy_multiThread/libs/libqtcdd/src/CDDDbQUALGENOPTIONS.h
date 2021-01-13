#ifndef VECTOR_CDD_CDDDBQUALGENOPTIONS_H
#define VECTOR_CDD_CDDDBQUALGENOPTIONS_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {


/**
 * @brief element QUALGENOPTIONS
 *
 */
class VECTOR_CDD_API CDDDbQUALGENOPTIONS
{
public:
    CDDDbQUALGENOPTIONS();
    ~CDDDbQUALGENOPTIONS();

    void load(const QDomElement &element);

    /** @attribute case */
    QString m_case;

    /** @attribute maxLen */
    QString m_maxLen;

    /** @attribute minLen */
    QString m_minLen;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBQUALGENOPTIONS_H

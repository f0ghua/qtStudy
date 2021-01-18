#ifndef VECTOR_CDD_CDDDBQUALGENOPTIONS_H
#define VECTOR_CDD_CDDDBQUALGENOPTIONS_H

#include "CDDDbQUALGENOPTIONSImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element QUALGENOPTIONS
 *
 */
class VECTOR_CDD_API CDDDbQUALGENOPTIONS : public CDDDbQUALGENOPTIONSImpl
{
public:
    CDDDbQUALGENOPTIONS();
    ~CDDDbQUALGENOPTIONS();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBQUALGENOPTIONS_H

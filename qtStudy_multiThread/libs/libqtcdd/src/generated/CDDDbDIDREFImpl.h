#ifndef VECTOR_CDD_CDDDBDIDREFIMPL_H
#define VECTOR_CDD_CDDDBDIDREFIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {


/**
 * @brief element DIDREF
 *
 */
class VECTOR_CDD_API CDDDbDIDREFImpl
{
public:
    CDDDbDIDREFImpl();
    ~CDDDbDIDREFImpl();

    void load(const QDomElement &element);

    /** @attribute didRef */
    QString m_didRef;

    QString m_text;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDIDREFIMPL_H

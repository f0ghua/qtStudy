#ifndef VECTOR_CDD_CDDDBDIDREF_H
#define VECTOR_CDD_CDDDBDIDREF_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {


/**
 * @brief element DIDREF
 *
 */
class VECTOR_CDD_API CDDDbDIDREF
{
public:
    CDDDbDIDREF();
    ~CDDDbDIDREF();

    void load(const QDomElement &element);

    /** @attribute didRef */
    QString m_didRef;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDIDREF_H

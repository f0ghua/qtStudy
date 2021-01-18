#ifndef VECTOR_CDD_CDDDBCOMMONSTRINGIMPL_H
#define VECTOR_CDD_CDDDBCOMMONSTRINGIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {


/**
 * @brief element COMMONSTRING
 *
 */
class VECTOR_CDD_API CDDDbCOMMONSTRINGImpl
{
public:
    CDDDbCOMMONSTRINGImpl();
    ~CDDDbCOMMONSTRINGImpl();

    void load(const QDomElement &element);

    QString m_text;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBCOMMONSTRINGIMPL_H

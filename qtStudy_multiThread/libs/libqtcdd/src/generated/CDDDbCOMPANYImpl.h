#ifndef VECTOR_CDD_CDDDBCOMPANYIMPL_H
#define VECTOR_CDD_CDDDBCOMPANYIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {


/**
 * @brief element COMPANY
 *
 */
class VECTOR_CDD_API CDDDbCOMPANYImpl
{
public:
    CDDDbCOMPANYImpl();
    ~CDDDbCOMPANYImpl();

    void load(const QDomElement &element);

    QString m_text;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBCOMPANYIMPL_H

#ifndef VECTOR_CDD_CDDDBLABELIMPL_H
#define VECTOR_CDD_CDDDBLABELIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {


/**
 * @brief element LABEL
 *
 */
class VECTOR_CDD_API CDDDbLABELImpl
{
public:
    CDDDbLABELImpl();
    ~CDDDbLABELImpl();

    void load(const QDomElement &element);

    QString m_text;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBLABELIMPL_H

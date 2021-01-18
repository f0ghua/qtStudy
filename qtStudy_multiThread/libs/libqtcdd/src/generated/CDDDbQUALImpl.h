#ifndef VECTOR_CDD_CDDDBQUALIMPL_H
#define VECTOR_CDD_CDDDBQUALIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {


/**
 * @brief element QUAL
 *
 */
class VECTOR_CDD_API CDDDbQUALImpl
{
public:
    CDDDbQUALImpl();
    ~CDDDbQUALImpl();

    void load(const QDomElement &element);

    QString m_text;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBQUALIMPL_H

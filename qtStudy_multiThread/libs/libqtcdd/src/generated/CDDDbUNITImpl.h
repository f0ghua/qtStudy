#ifndef VECTOR_CDD_CDDDBUNITIMPL_H
#define VECTOR_CDD_CDDDBUNITIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {


/**
 * @brief element UNIT
 *
 */
class VECTOR_CDD_API CDDDbUNITImpl
{
public:
    CDDDbUNITImpl();
    ~CDDDbUNITImpl();

    void load(const QDomElement &element);

    QString m_text;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBUNITIMPL_H

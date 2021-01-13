#ifndef VECTOR_CDD_CDDDBFC_H
#define VECTOR_CDD_CDDDBFC_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {


/**
 * @brief element FC
 *
 */
class VECTOR_CDD_API CDDDbFC
{
public:
    CDDDbFC();
    ~CDDDbFC();

    void load(const QDomElement &element);

    QString m_text;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBFC_H

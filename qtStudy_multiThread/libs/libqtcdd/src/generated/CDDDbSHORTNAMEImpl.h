#ifndef VECTOR_CDD_CDDDBSHORTNAMEIMPL_H
#define VECTOR_CDD_CDDDBSHORTNAMEIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {


/**
 * @brief element SHORTNAME
 *
 */
class VECTOR_CDD_API CDDDbSHORTNAMEImpl
{
public:
    CDDDbSHORTNAMEImpl();
    ~CDDDbSHORTNAMEImpl();

    void load(const QDomElement &element);

    QString m_text;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSHORTNAMEIMPL_H

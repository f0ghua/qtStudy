#ifndef VECTOR_CDD_CDDDBFIRSTNAMEIMPL_H
#define VECTOR_CDD_CDDDBFIRSTNAMEIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {


/**
 * @brief element FIRSTNAME
 *
 */
class VECTOR_CDD_API CDDDbFIRSTNAMEImpl
{
public:
    CDDDbFIRSTNAMEImpl();
    ~CDDDbFIRSTNAMEImpl();

    void load(const QDomElement &element);

    QString m_text;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBFIRSTNAMEIMPL_H

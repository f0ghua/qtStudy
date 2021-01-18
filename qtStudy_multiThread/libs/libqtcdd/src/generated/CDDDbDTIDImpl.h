#ifndef VECTOR_CDD_CDDDBDTIDIMPL_H
#define VECTOR_CDD_CDDDBDTIDIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {


/**
 * @brief element DTID
 *
 */
class VECTOR_CDD_API CDDDbDTIDImpl
{
public:
    CDDDbDTIDImpl();
    ~CDDDbDTIDImpl();

    void load(const QDomElement &element);

    QString m_text;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDTIDIMPL_H

#ifndef VECTOR_CDD_CDDDBDCLTMPLS_H
#define VECTOR_CDD_CDDDBDCLTMPLS_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbDCLTMPL;

/**
 * @brief element DCLTMPLS
 *
 */
class VECTOR_CDD_API CDDDbDCLTMPLS
{
public:
    CDDDbDCLTMPLS();
    ~CDDDbDCLTMPLS();

    void load(const QDomElement &element);

    /** @element DCLTMPL */
    QMap<QString, QSharedPointer<CDDDbDCLTMPL>> m_dcltmpls;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDCLTMPLS_H

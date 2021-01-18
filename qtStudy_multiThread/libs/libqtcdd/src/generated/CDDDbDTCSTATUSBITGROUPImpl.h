#ifndef VECTOR_CDD_CDDDBDTCSTATUSBITGROUPIMPL_H
#define VECTOR_CDD_CDDDBDTCSTATUSBITGROUPIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {


/**
 * @brief element DTCSTATUSBITGROUP
 *
 */
class VECTOR_CDD_API CDDDbDTCSTATUSBITGROUPImpl
{
public:
    CDDDbDTCSTATUSBITGROUPImpl();
    ~CDDDbDTCSTATUSBITGROUPImpl();

    void load(const QDomElement &element);

    /** @attribute conv */
    QString m_conv;

    /** @attribute dtref */
    QString m_dtref;

    QString m_text;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDTCSTATUSBITGROUPIMPL_H

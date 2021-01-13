#ifndef VECTOR_CDD_CDDDBDTCSTATUSBITGROUP_H
#define VECTOR_CDD_CDDDBDTCSTATUSBITGROUP_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {


/**
 * @brief element DTCSTATUSBITGROUP
 *
 */
class VECTOR_CDD_API CDDDbDTCSTATUSBITGROUP
{
public:
    CDDDbDTCSTATUSBITGROUP();
    ~CDDDbDTCSTATUSBITGROUP();

    void load(const QDomElement &element);

    /** @attribute conv */
    QString m_conv;

    /** @attribute dtref */
    QString m_dtref;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDTCSTATUSBITGROUP_H

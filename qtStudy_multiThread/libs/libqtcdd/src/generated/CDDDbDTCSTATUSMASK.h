#ifndef VECTOR_CDD_CDDDBDTCSTATUSMASK_H
#define VECTOR_CDD_CDDDBDTCSTATUSMASK_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbDTCSTATUSBITGROUP;

/**
 * @brief element DTCSTATUSMASK
 *
 */
class VECTOR_CDD_API CDDDbDTCSTATUSMASK
{
public:
    CDDDbDTCSTATUSMASK();
    ~CDDDbDTCSTATUSMASK();

    void load(const QDomElement &element);

    /** @attribute dtref */
    QString m_dtref;

    /** @element DTCSTATUSBITGROUP */
    QVector<QSharedPointer<CDDDbDTCSTATUSBITGROUP>> m_dtcstatusbitgroups;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDTCSTATUSMASK_H

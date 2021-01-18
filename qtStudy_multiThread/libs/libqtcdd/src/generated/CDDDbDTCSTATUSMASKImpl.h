#ifndef VECTOR_CDD_CDDDBDTCSTATUSMASKIMPL_H
#define VECTOR_CDD_CDDDBDTCSTATUSMASKIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbDTCSTATUSBITGROUP;

/**
 * @brief element DTCSTATUSMASK
 *
 */
class VECTOR_CDD_API CDDDbDTCSTATUSMASKImpl
{
public:
    CDDDbDTCSTATUSMASKImpl();
    ~CDDDbDTCSTATUSMASKImpl();

    void load(const QDomElement &element);

    /** @attribute dtref */
    QString m_dtref;

    QString m_text;

    /** @element DTCSTATUSBITGROUP */
    QVector<QSharedPointer<CDDDbDTCSTATUSBITGROUP>> m_elDtcstatusbitgroups;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDTCSTATUSMASKIMPL_H

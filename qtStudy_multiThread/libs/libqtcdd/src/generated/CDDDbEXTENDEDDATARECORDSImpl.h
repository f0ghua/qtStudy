#ifndef VECTOR_CDD_CDDDBEXTENDEDDATARECORDSIMPL_H
#define VECTOR_CDD_CDDDBEXTENDEDDATARECORDSIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbEXTENDEDDATARECORD;

/**
 * @brief element EXTENDEDDATARECORDS
 *
 */
class VECTOR_CDD_API CDDDbEXTENDEDDATARECORDSImpl
{
public:
    CDDDbEXTENDEDDATARECORDSImpl();
    ~CDDDbEXTENDEDDATARECORDSImpl();

    void load(const QDomElement &element);

    QString m_text;

    /** @element EXTENDEDDATARECORD */
    QSharedPointer<CDDDbEXTENDEDDATARECORD> m_elExtendeddatarecord;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBEXTENDEDDATARECORDSIMPL_H

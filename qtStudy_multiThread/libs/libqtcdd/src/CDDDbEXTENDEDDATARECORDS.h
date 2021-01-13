#ifndef VECTOR_CDD_CDDDBEXTENDEDDATARECORDS_H
#define VECTOR_CDD_CDDDBEXTENDEDDATARECORDS_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbEXTENDEDDATARECORD;

/**
 * @brief element EXTENDEDDATARECORDS
 *
 */
class VECTOR_CDD_API CDDDbEXTENDEDDATARECORDS
{
public:
    CDDDbEXTENDEDDATARECORDS();
    ~CDDDbEXTENDEDDATARECORDS();

    void load(const QDomElement &element);

    /** @element EXTENDEDDATARECORD */
    QSharedPointer<CDDDbEXTENDEDDATARECORD> m_extendeddatarecord;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBEXTENDEDDATARECORDS_H

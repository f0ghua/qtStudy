#ifndef VECTOR_CDD_CDDDBRECORDDTPOOL_H
#define VECTOR_CDD_CDDDBRECORDDTPOOL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbRECORDDT;

/**
 * @brief element RECORDDTPOOL
 *
 */
class VECTOR_CDD_API CDDDbRECORDDTPOOL
{
public:
    CDDDbRECORDDTPOOL();
    ~CDDDbRECORDDTPOOL();

    void load(const QDomElement &element);

    /** @element RECORDDT */
    QSharedPointer<CDDDbRECORDDT> m_recorddt;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBRECORDDTPOOL_H

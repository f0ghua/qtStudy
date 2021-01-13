#ifndef VECTOR_CDD_CDDDBHISTITEMS_H
#define VECTOR_CDD_CDDDBHISTITEMS_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbHISTITEM;

/**
 * @brief element HISTITEMS
 *
 */
class VECTOR_CDD_API CDDDbHISTITEMS
{
public:
    CDDDbHISTITEMS();
    ~CDDDbHISTITEMS();

    void load(const QDomElement &element);

    /** @element HISTITEM */
    QSharedPointer<CDDDbHISTITEM> m_histitem;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBHISTITEMS_H

#ifndef VECTOR_CDD_CDDDBHISTITEMSIMPL_H
#define VECTOR_CDD_CDDDBHISTITEMSIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbHISTITEM;

/**
 * @brief element HISTITEMS
 *
 */
class VECTOR_CDD_API CDDDbHISTITEMSImpl
{
public:
    CDDDbHISTITEMSImpl();
    ~CDDDbHISTITEMSImpl();

    void load(const QDomElement &element);

    QString m_text;

    /** @element HISTITEM */
    QVector<QSharedPointer<CDDDbHISTITEM>> m_elHistitems;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBHISTITEMSIMPL_H

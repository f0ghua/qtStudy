#ifndef VECTOR_CDD_CDDDBHISTITEM_H
#define VECTOR_CDD_CDDDBHISTITEM_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbLABEL;
class CDDDbMOD;
class CDDDbREASON;

/**
 * @brief element HISTITEM
 *
 */
class VECTOR_CDD_API CDDDbHISTITEM
{
public:
    CDDDbHISTITEM();
    ~CDDDbHISTITEM();

    void load(const QDomElement &element);

    /** @attribute authorref */
    QString m_authorref;

    /** @attribute dt */
    QString m_dt;

    /** @attribute stid */
    QString m_stid;

    /** @attribute tool */
    QString m_tool;

    /** @element LABEL */
    QSharedPointer<CDDDbLABEL> m_label;

    /** @element MOD */
    QSharedPointer<CDDDbMOD> m_mod;

    /** @element REASON */
    QSharedPointer<CDDDbREASON> m_reason;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBHISTITEM_H

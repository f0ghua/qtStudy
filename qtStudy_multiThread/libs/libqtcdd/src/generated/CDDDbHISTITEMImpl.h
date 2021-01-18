#ifndef VECTOR_CDD_CDDDBHISTITEMIMPL_H
#define VECTOR_CDD_CDDDBHISTITEMIMPL_H

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
class VECTOR_CDD_API CDDDbHISTITEMImpl
{
public:
    CDDDbHISTITEMImpl();
    ~CDDDbHISTITEMImpl();

    void load(const QDomElement &element);

    /** @attribute authorref */
    QString m_authorref;

    /** @attribute dt */
    QString m_dt;

    /** @attribute stid */
    QString m_stid;

    /** @attribute tool */
    QString m_tool;

    QString m_text;

    /** @element LABEL */
    QSharedPointer<CDDDbLABEL> m_elLabel;

    /** @element MOD */
    QSharedPointer<CDDDbMOD> m_elMod;

    /** @element REASON */
    QSharedPointer<CDDDbREASON> m_elReason;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBHISTITEMIMPL_H

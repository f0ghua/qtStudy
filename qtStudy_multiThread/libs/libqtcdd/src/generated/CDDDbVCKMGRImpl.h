#ifndef VECTOR_CDD_CDDDBVCKMGRIMPL_H
#define VECTOR_CDD_CDDDBVCKMGRIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {


/**
 * @brief element VCKMGR
 *
 */
class VECTOR_CDD_API CDDDbVCKMGRImpl
{
public:
    CDDDbVCKMGRImpl();
    ~CDDDbVCKMGRImpl();

    void load(const QDomElement &element);

    /** @attribute vckmax */
    QString m_vckmax;

    /** @attribute vckmin */
    QString m_vckmin;

    /** @attribute vckmode */
    QString m_vckmode;

    /** @attribute vcknext */
    QString m_vcknext;

    QString m_text;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBVCKMGRIMPL_H

#ifndef VECTOR_CDD_CDDDBVCKMGR_H
#define VECTOR_CDD_CDDDBVCKMGR_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {


/**
 * @brief element VCKMGR
 *
 */
class VECTOR_CDD_API CDDDbVCKMGR
{
public:
    CDDDbVCKMGR();
    ~CDDDbVCKMGR();

    void load(const QDomElement &element);

    /** @attribute vckmax */
    QString m_vckmax;

    /** @attribute vckmin */
    QString m_vckmin;

    /** @attribute vckmode */
    QString m_vckmode;

    /** @attribute vcknext */
    QString m_vcknext;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBVCKMGR_H

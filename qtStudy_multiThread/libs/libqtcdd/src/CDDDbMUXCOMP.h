#ifndef VECTOR_CDD_CDDDBMUXCOMP_H
#define VECTOR_CDD_CDDDBMUXCOMP_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbNAME;
class CDDDbQUAL;

/**
 * @brief element MUXCOMP
 *
 */
class VECTOR_CDD_API CDDDbMUXCOMP
{
public:
    CDDDbMUXCOMP();
    ~CDDDbMUXCOMP();

    void load(const QDomElement &element);

    /** @attribute dest */
    QString m_dest;

    /** @attribute id */
    QString m_id;

    /** @attribute minbl */
    QString m_minbl;

    /** @attribute must */
    QString m_must;

    /** @attribute oid */
    QString m_oid;

    /** @attribute selbm */
    QString m_selbm;

    /** @attribute selref */
    QString m_selref;

    /** @attribute temploid */
    QString m_temploid;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_name;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_qual;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBMUXCOMP_H

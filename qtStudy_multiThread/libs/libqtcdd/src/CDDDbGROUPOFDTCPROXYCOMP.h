#ifndef VECTOR_CDD_CDDDBGROUPOFDTCPROXYCOMP_H
#define VECTOR_CDD_CDDDBGROUPOFDTCPROXYCOMP_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbNAME;
class CDDDbQUAL;

/**
 * @brief element GROUPOFDTCPROXYCOMP
 *
 */
class VECTOR_CDD_API CDDDbGROUPOFDTCPROXYCOMP
{
public:
    CDDDbGROUPOFDTCPROXYCOMP();
    ~CDDDbGROUPOFDTCPROXYCOMP();

    void load(const QDomElement &element);

    /** @attribute dest */
    QString m_dest;

    /** @attribute dtref */
    QString m_dtref;

    /** @attribute id */
    QString m_id;

    /** @attribute maxbl */
    QString m_maxbl;

    /** @attribute minbl */
    QString m_minbl;

    /** @attribute must */
    QString m_must;

    /** @attribute oid */
    QString m_oid;

    /** @attribute temploid */
    QString m_temploid;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_name;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_qual;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBGROUPOFDTCPROXYCOMP_H

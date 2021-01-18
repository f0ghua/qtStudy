#ifndef VECTOR_CDD_CDDDBGROUPOFDTCPROXYCOMPIMPL_H
#define VECTOR_CDD_CDDDBGROUPOFDTCPROXYCOMPIMPL_H

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
class VECTOR_CDD_API CDDDbGROUPOFDTCPROXYCOMPImpl
{
public:
    CDDDbGROUPOFDTCPROXYCOMPImpl();
    ~CDDDbGROUPOFDTCPROXYCOMPImpl();

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

    QString m_text;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_elName;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_elQual;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBGROUPOFDTCPROXYCOMPIMPL_H

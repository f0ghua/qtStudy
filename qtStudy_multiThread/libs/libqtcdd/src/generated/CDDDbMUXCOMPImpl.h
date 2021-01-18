#ifndef VECTOR_CDD_CDDDBMUXCOMPIMPL_H
#define VECTOR_CDD_CDDDBMUXCOMPIMPL_H

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
class VECTOR_CDD_API CDDDbMUXCOMPImpl
{
public:
    CDDDbMUXCOMPImpl();
    ~CDDDbMUXCOMPImpl();

    void load(const QDomElement &element);

    /** @attribute dest */
    QString m_dest;

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

    /** @attribute selbm */
    QString m_selbm;

    /** @attribute selref */
    QString m_selref;

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

#endif // VECTOR_CDD_CDDDBMUXCOMPIMPL_H

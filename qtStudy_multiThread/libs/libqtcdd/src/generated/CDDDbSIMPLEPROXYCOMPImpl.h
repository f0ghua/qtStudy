#ifndef VECTOR_CDD_CDDDBSIMPLEPROXYCOMPIMPL_H
#define VECTOR_CDD_CDDDBSIMPLEPROXYCOMPIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbDESC;
class CDDDbNAME;
class CDDDbQUAL;

/**
 * @brief element SIMPLEPROXYCOMP
 *
 */
class VECTOR_CDD_API CDDDbSIMPLEPROXYCOMPImpl
{
public:
    CDDDbSIMPLEPROXYCOMPImpl();
    ~CDDDbSIMPLEPROXYCOMPImpl();

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

    /** @attribute mustAtRT */
    QString m_mustAtRT;

    /** @attribute oid */
    QString m_oid;

    /** @attribute temploid */
    QString m_temploid;

    QString m_text;

    /** @element DESC */
    QSharedPointer<CDDDbDESC> m_elDesc;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_elName;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_elQual;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSIMPLEPROXYCOMPIMPL_H

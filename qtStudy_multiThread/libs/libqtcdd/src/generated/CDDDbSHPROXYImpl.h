#ifndef VECTOR_CDD_CDDDBSHPROXYIMPL_H
#define VECTOR_CDD_CDDDBSHPROXYIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbNAME;
class CDDDbPROXYCOMPREF;
class CDDDbQUAL;

/**
 * @brief element SHPROXY
 *
 */
class VECTOR_CDD_API CDDDbSHPROXYImpl
{
public:
    CDDDbSHPROXYImpl();
    ~CDDDbSHPROXYImpl();

    void load(const QDomElement &element);

    /** @attribute dest */
    QString m_dest;

    /** @attribute id */
    QString m_id;

    /** @attribute oid */
    QString m_oid;

    /** @attribute spec */
    QString m_spec;

    /** @attribute temploid */
    QString m_temploid;

    /** @attribute xdtauth */
    QString m_xdtauth;

    QString m_text;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_elName;

    /** @element PROXYCOMPREF */
    QVector<QSharedPointer<CDDDbPROXYCOMPREF>> m_elProxycomprefs;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_elQual;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSHPROXYIMPL_H

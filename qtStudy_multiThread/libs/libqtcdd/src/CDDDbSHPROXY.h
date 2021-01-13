#ifndef VECTOR_CDD_CDDDBSHPROXY_H
#define VECTOR_CDD_CDDDBSHPROXY_H

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
class VECTOR_CDD_API CDDDbSHPROXY
{
public:
    CDDDbSHPROXY();
    ~CDDDbSHPROXY();

    void load(const QDomElement &element);

    /** @attribute dest */
    QString m_dest;

    /** @attribute id */
    QString m_id;

    /** @attribute oid */
    QString m_oid;

    /** @attribute temploid */
    QString m_temploid;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_name;

    /** @element PROXYCOMPREF */
    QVector<QSharedPointer<CDDDbPROXYCOMPREF>> m_proxycomprefs;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_qual;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSHPROXY_H

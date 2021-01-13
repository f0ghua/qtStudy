#ifndef VECTOR_CDD_CDDDBDIDCOMMONSNAPSHOTDATA_H
#define VECTOR_CDD_CDDDBDIDCOMMONSNAPSHOTDATA_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbNAME;
class CDDDbQUAL;

/**
 * @brief element DIDCOMMONSNAPSHOTDATA
 *
 */
class VECTOR_CDD_API CDDDbDIDCOMMONSNAPSHOTDATA
{
public:
    CDDDbDIDCOMMONSNAPSHOTDATA();
    ~CDDDbDIDCOMMONSNAPSHOTDATA();

    void load(const QDomElement &element);

    /** @attribute id */
    QString m_id;

    /** @attribute oid */
    QString m_oid;

    /** @attribute supportDtcSpecificData */
    QString m_supportDtcSpecificData;

    /** @attribute temploid */
    QString m_temploid;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_name;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_qual;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDIDCOMMONSNAPSHOTDATA_H

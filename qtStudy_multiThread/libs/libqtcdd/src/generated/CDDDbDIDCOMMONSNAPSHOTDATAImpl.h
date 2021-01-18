#ifndef VECTOR_CDD_CDDDBDIDCOMMONSNAPSHOTDATAIMPL_H
#define VECTOR_CDD_CDDDBDIDCOMMONSNAPSHOTDATAIMPL_H

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
class VECTOR_CDD_API CDDDbDIDCOMMONSNAPSHOTDATAImpl
{
public:
    CDDDbDIDCOMMONSNAPSHOTDATAImpl();
    ~CDDDbDIDCOMMONSNAPSHOTDATAImpl();

    void load(const QDomElement &element);

    /** @attribute id */
    QString m_id;

    /** @attribute oid */
    QString m_oid;

    /** @attribute supportDtcSpecificData */
    QString m_supportDtcSpecificData;

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

#endif // VECTOR_CDD_CDDDBDIDCOMMONSNAPSHOTDATAIMPL_H

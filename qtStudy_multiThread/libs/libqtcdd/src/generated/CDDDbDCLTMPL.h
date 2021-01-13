#ifndef VECTOR_CDD_CDDDBDCLTMPL_H
#define VECTOR_CDD_CDDDBDCLTMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbDCLSRVTMPL;
class CDDDbDESC;
class CDDDbNAME;
class CDDDbQUAL;
class CDDDbSHPROXY;
class CDDDbSHSTATIC;

/**
 * @brief element DCLTMPL
 *
 */
class VECTOR_CDD_API CDDDbDCLTMPL
{
public:
    CDDDbDCLTMPL();
    ~CDDDbDCLTMPL();

    void load(const QDomElement &element);

    /** @attribute cls */
    QString m_cls;

    /** @attribute id */
    QString m_id;

    /** @attribute oid */
    QString m_oid;

    /** @attribute single */
    QString m_single;

    /** @attribute temploid */
    QString m_temploid;

    /** @element DCLSRVTMPL */
    QMap<QString, QSharedPointer<CDDDbDCLSRVTMPL>> m_dclsrvtmpls;

    /** @element DESC */
    QSharedPointer<CDDDbDESC> m_desc;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_name;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_qual;

    /** @element SHPROXY */
    QMap<QString, QSharedPointer<CDDDbSHPROXY>> m_shproxys;

    /** @element SHSTATIC */
    QSharedPointer<CDDDbSHSTATIC> m_shstatic;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDCLTMPL_H

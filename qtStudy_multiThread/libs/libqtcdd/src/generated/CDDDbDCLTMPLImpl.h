#ifndef VECTOR_CDD_CDDDBDCLTMPLIMPL_H
#define VECTOR_CDD_CDDDBDCLTMPLIMPL_H

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
class VECTOR_CDD_API CDDDbDCLTMPLImpl
{
public:
    CDDDbDCLTMPLImpl();
    ~CDDDbDCLTMPLImpl();

    void load(const QDomElement &element);

    /** @attribute cls */
    QString m_cls;

    /** @attribute id */
    QString m_id;

    /** @attribute isRelevantForReq */
    QString m_isRelevantForReq;

    /** @attribute oid */
    QString m_oid;

    /** @attribute single */
    QString m_single;

    /** @attribute temploid */
    QString m_temploid;

    QString m_text;

    /** @element DCLSRVTMPL */
    QMap<QString, QSharedPointer<CDDDbDCLSRVTMPL>> m_elDclsrvtmpls;

    /** @element DESC */
    QSharedPointer<CDDDbDESC> m_elDesc;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_elName;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_elQual;

    /** @element SHPROXY */
    QMap<QString, QSharedPointer<CDDDbSHPROXY>> m_elShproxys;

    /** @element SHSTATIC */
    QSharedPointer<CDDDbSHSTATIC> m_elShstatic;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDCLTMPLIMPL_H

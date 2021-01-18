#ifndef VECTOR_CDD_CDDDBDCLSRVTMPLIMPL_H
#define VECTOR_CDD_CDDDBDCLSRVTMPLIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbNAME;
class CDDDbQUAL;

/**
 * @brief element DCLSRVTMPL
 *
 */
class VECTOR_CDD_API CDDDbDCLSRVTMPLImpl
{
public:
    CDDDbDCLSRVTMPLImpl();
    ~CDDDbDCLSRVTMPLImpl();

    void load(const QDomElement &element);

    /** @attribute conv */
    QString m_conv;

    /** @attribute dtref */
    QString m_dtref;

    /** @attribute id */
    QString m_id;

    /** @attribute mayBeExec */
    QString m_mayBeExec;

    /** @attribute oid */
    QString m_oid;

    /** @attribute temploid */
    QString m_temploid;

    /** @attribute tmplref */
    QString m_tmplref;

    QString m_text;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_elName;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_elQual;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDCLSRVTMPLIMPL_H

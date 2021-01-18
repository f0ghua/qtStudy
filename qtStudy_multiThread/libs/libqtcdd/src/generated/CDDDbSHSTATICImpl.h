#ifndef VECTOR_CDD_CDDDBSHSTATICIMPL_H
#define VECTOR_CDD_CDDDBSHSTATICIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbNAME;
class CDDDbQUAL;
class CDDDbSTATICCOMPREF;

/**
 * @brief element SHSTATIC
 *
 */
class VECTOR_CDD_API CDDDbSHSTATICImpl
{
public:
    CDDDbSHSTATICImpl();
    ~CDDDbSHSTATICImpl();

    void load(const QDomElement &element);

    /** @attribute id */
    QString m_id;

    /** @attribute oid */
    QString m_oid;

    /** @attribute spec */
    QString m_spec;

    /** @attribute temploid */
    QString m_temploid;

    QString m_text;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_elName;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_elQual;

    /** @element STATICCOMPREF */
    QVector<QSharedPointer<CDDDbSTATICCOMPREF>> m_elStaticcomprefs;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSHSTATICIMPL_H

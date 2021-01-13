#ifndef VECTOR_CDD_CDDDBSHSTATIC_H
#define VECTOR_CDD_CDDDBSHSTATIC_H

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
class VECTOR_CDD_API CDDDbSHSTATIC
{
public:
    CDDDbSHSTATIC();
    ~CDDDbSHSTATIC();

    void load(const QDomElement &element);

    /** @attribute id */
    QString m_id;

    /** @attribute oid */
    QString m_oid;

    /** @attribute spec */
    QString m_spec;

    /** @attribute temploid */
    QString m_temploid;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_name;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_qual;

    /** @element STATICCOMPREF */
    QVector<QSharedPointer<CDDDbSTATICCOMPREF>> m_staticcomprefs;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSHSTATIC_H

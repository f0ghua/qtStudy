#ifndef VECTOR_CDD_CDDDBTARGETGROUPIMPL_H
#define VECTOR_CDD_CDDDBTARGETGROUPIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbNAME;
class CDDDbQUAL;

/**
 * @brief element TARGETGROUP
 *
 */
class VECTOR_CDD_API CDDDbTARGETGROUPImpl
{
public:
    CDDDbTARGETGROUPImpl();
    ~CDDDbTARGETGROUPImpl();

    void load(const QDomElement &element);

    /** @attribute oid */
    QString m_oid;

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

#endif // VECTOR_CDD_CDDDBTARGETGROUPIMPL_H

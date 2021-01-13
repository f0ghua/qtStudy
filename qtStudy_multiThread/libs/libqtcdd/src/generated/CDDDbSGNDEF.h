#ifndef VECTOR_CDD_CDDDBSGNDEF_H
#define VECTOR_CDD_CDDDBSGNDEF_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbNAME;
class CDDDbQUAL;

/**
 * @brief element SGNDEF
 *
 */
class VECTOR_CDD_API CDDDbSGNDEF
{
public:
    CDDDbSGNDEF();
    ~CDDDbSGNDEF();

    void load(const QDomElement &element);

    /** @attribute attrcatref */
    QString m_attrcatref;

    /** @attribute id */
    QString m_id;

    /** @attribute oid */
    QString m_oid;

    /** @attribute temploid */
    QString m_temploid;

    /** @attribute v */
    QString m_v;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_name;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_qual;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSGNDEF_H

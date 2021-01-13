#ifndef VECTOR_CDD_CDDDBDOMAINDATAPROXYCOMP_H
#define VECTOR_CDD_CDDDBDOMAINDATAPROXYCOMP_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbNAME;
class CDDDbQUAL;

/**
 * @brief element DOMAINDATAPROXYCOMP
 *
 */
class VECTOR_CDD_API CDDDbDOMAINDATAPROXYCOMP
{
public:
    CDDDbDOMAINDATAPROXYCOMP();
    ~CDDDbDOMAINDATAPROXYCOMP();

    void load(const QDomElement &element);

    /** @attribute dest */
    QString m_dest;

    /** @attribute id */
    QString m_id;

    /** @attribute must */
    QString m_must;

    /** @attribute oid */
    QString m_oid;

    /** @attribute temploid */
    QString m_temploid;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_name;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_qual;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDOMAINDATAPROXYCOMP_H

#ifndef VECTOR_CDD_CDDDBSTATE_H
#define VECTOR_CDD_CDDDBSTATE_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbDESC;
class CDDDbNAME;
class CDDDbQUAL;

/**
 * @brief element STATE
 *
 */
class VECTOR_CDD_API CDDDbSTATE
{
public:
    CDDDbSTATE();
    ~CDDDbSTATE();

    void load(const QDomElement &element);

    /** @attribute oid */
    QString m_oid;

    /** @attribute temploid */
    QString m_temploid;

    /** @element DESC */
    QSharedPointer<CDDDbDESC> m_desc;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_name;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_qual;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSTATE_H

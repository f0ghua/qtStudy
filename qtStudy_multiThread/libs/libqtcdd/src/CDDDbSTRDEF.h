#ifndef VECTOR_CDD_CDDDBSTRDEF_H
#define VECTOR_CDD_CDDDBSTRDEF_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbDESC;
class CDDDbNAME;
class CDDDbQUAL;
class CDDDbSTRING;

/**
 * @brief element STRDEF
 *
 */
class VECTOR_CDD_API CDDDbSTRDEF
{
public:
    CDDDbSTRDEF();
    ~CDDDbSTRDEF();

    void load(const QDomElement &element);

    /** @attribute attrcatref */
    QString m_attrcatref;

    /** @attribute id */
    QString m_id;

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

    /** @element STRING */
    QSharedPointer<CDDDbSTRING> m_string;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSTRDEF_H

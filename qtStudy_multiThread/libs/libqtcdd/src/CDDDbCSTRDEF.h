#ifndef VECTOR_CDD_CDDDBCSTRDEF_H
#define VECTOR_CDD_CDDDBCSTRDEF_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbCOMMONSTRING;
class CDDDbDESC;
class CDDDbNAME;
class CDDDbQUAL;

/**
 * @brief element CSTRDEF
 *
 */
class VECTOR_CDD_API CDDDbCSTRDEF
{
public:
    CDDDbCSTRDEF();
    ~CDDDbCSTRDEF();

    void load(const QDomElement &element);

    /** @attribute attrcatref */
    QString m_attrcatref;

    /** @attribute id */
    QString m_id;

    /** @attribute oid */
    QString m_oid;

    /** @attribute temploid */
    QString m_temploid;

    /** @element COMMONSTRING */
    QSharedPointer<CDDDbCOMMONSTRING> m_commonstring;

    /** @element DESC */
    QSharedPointer<CDDDbDESC> m_desc;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_name;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_qual;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBCSTRDEF_H

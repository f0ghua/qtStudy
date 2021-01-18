#ifndef VECTOR_CDD_CDDDBCSTRDEFIMPL_H
#define VECTOR_CDD_CDDDBCSTRDEFIMPL_H

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
class VECTOR_CDD_API CDDDbCSTRDEFImpl
{
public:
    CDDDbCSTRDEFImpl();
    ~CDDDbCSTRDEFImpl();

    void load(const QDomElement &element);

    /** @attribute attrcatref */
    QString m_attrcatref;

    /** @attribute id */
    QString m_id;

    /** @attribute listable */
    QString m_listable;

    /** @attribute mayBeReported */
    QString m_mayBeReported;

    /** @attribute oid */
    QString m_oid;

    /** @attribute restr */
    QString m_restr;

    /** @attribute temploid */
    QString m_temploid;

    /** @attribute usage */
    QString m_usage;

    /** @attribute xauth */
    QString m_xauth;

    QString m_text;

    /** @element COMMONSTRING */
    QSharedPointer<CDDDbCOMMONSTRING> m_elCommonstring;

    /** @element DESC */
    QSharedPointer<CDDDbDESC> m_elDesc;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_elName;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_elQual;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBCSTRDEFIMPL_H

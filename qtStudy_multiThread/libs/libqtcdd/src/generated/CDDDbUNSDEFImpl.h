#ifndef VECTOR_CDD_CDDDBUNSDEFIMPL_H
#define VECTOR_CDD_CDDDBUNSDEFIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbDESC;
class CDDDbNAME;
class CDDDbQUAL;

/**
 * @brief element UNSDEF
 *
 */
class VECTOR_CDD_API CDDDbUNSDEFImpl
{
public:
    CDDDbUNSDEFImpl();
    ~CDDDbUNSDEFImpl();

    void load(const QDomElement &element);

    /** @attribute attrcatref */
    QString m_attrcatref;

    /** @attribute df */
    QString m_df;

    /** @attribute id */
    QString m_id;

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

    /** @attribute v */
    QString m_v;

    /** @attribute xauth */
    QString m_xauth;

    QString m_text;

    /** @element DESC */
    QSharedPointer<CDDDbDESC> m_elDesc;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_elName;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_elQual;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBUNSDEFIMPL_H

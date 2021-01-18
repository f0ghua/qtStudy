#ifndef VECTOR_CDD_CDDDBENUMDEFIMPL_H
#define VECTOR_CDD_CDDDBENUMDEFIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbDESC;
class CDDDbETAG;
class CDDDbNAME;
class CDDDbQUAL;

/**
 * @brief element ENUMDEF
 *
 */
class VECTOR_CDD_API CDDDbENUMDEFImpl
{
public:
    CDDDbENUMDEFImpl();
    ~CDDDbENUMDEFImpl();

    void load(const QDomElement &element);

    /** @attribute attrcatref */
    QString m_attrcatref;

    /** @attribute id */
    QString m_id;

    /** @attribute mayBeReported */
    QString m_mayBeReported;

    /** @attribute oid */
    QString m_oid;

    /** @attribute restr */
    QString m_restr;

    /** @attribute sort */
    QString m_sort;

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

    /** @element ETAG */
    QVector<QSharedPointer<CDDDbETAG>> m_elEtags;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_elName;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_elQual;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBENUMDEFIMPL_H

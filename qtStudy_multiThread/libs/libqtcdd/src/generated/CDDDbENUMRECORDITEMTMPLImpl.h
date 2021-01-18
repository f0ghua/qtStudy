#ifndef VECTOR_CDD_CDDDBENUMRECORDITEMTMPLIMPL_H
#define VECTOR_CDD_CDDDBENUMRECORDITEMTMPLIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbDESC;
class CDDDbETAG;
class CDDDbNAME;
class CDDDbQUAL;

/**
 * @brief element ENUMRECORDITEMTMPL
 *
 */
class VECTOR_CDD_API CDDDbENUMRECORDITEMTMPLImpl
{
public:
    CDDDbENUMRECORDITEMTMPLImpl();
    ~CDDDbENUMRECORDITEMTMPLImpl();

    void load(const QDomElement &element);

    /** @attribute conv */
    QString m_conv;

    /** @attribute id */
    QString m_id;

    /** @attribute mayBeDup */
    QString m_mayBeDup;

    /** @attribute oid */
    QString m_oid;

    /** @attribute sort */
    QString m_sort;

    /** @attribute temploid */
    QString m_temploid;

    /** @attribute v */
    QString m_v;

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

#endif // VECTOR_CDD_CDDDBENUMRECORDITEMTMPLIMPL_H

#ifndef VECTOR_CDD_CDDDBENUMRECORDITEMTMPL_H
#define VECTOR_CDD_CDDDBENUMRECORDITEMTMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbETAG;
class CDDDbNAME;
class CDDDbQUAL;

/**
 * @brief element ENUMRECORDITEMTMPL
 *
 */
class VECTOR_CDD_API CDDDbENUMRECORDITEMTMPL
{
public:
    CDDDbENUMRECORDITEMTMPL();
    ~CDDDbENUMRECORDITEMTMPL();

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

    /** @element ETAG */
    QVector<QSharedPointer<CDDDbETAG>> m_etags;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_name;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_qual;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBENUMRECORDITEMTMPL_H

#ifndef VECTOR_CDD_CDDDBRECORD_H
#define VECTOR_CDD_CDDDBRECORD_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbENUMRECORDITEM;
class CDDDbTEXT;
class CDDDbTRRECORDITEM;
class CDDDbUNSRECORDITEM;

/**
 * @brief element RECORD
 *
 */
class VECTOR_CDD_API CDDDbRECORD
{
public:
    CDDDbRECORD();
    ~CDDDbRECORD();

    void load(const QDomElement &element);

    /** @attribute id */
    QString m_id;

    /** @attribute oid */
    QString m_oid;

    /** @attribute v */
    QString m_v;

    /** @element ENUMRECORDITEM */
    QVector<QSharedPointer<CDDDbENUMRECORDITEM>> m_enumrecorditems;

    /** @element TEXT */
    QSharedPointer<CDDDbTEXT> m_text;

    /** @element TRRECORDITEM */
    QVector<QSharedPointer<CDDDbTRRECORDITEM>> m_trrecorditems;

    /** @element UNSRECORDITEM */
    QVector<QSharedPointer<CDDDbUNSRECORDITEM>> m_unsrecorditems;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBRECORD_H

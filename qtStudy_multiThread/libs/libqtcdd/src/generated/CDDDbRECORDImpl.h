#ifndef VECTOR_CDD_CDDDBRECORDIMPL_H
#define VECTOR_CDD_CDDDBRECORDIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbCSTR;
class CDDDbENUM;
class CDDDbENUMRECORDITEM;
class CDDDbTEXT;
class CDDDbTRRECORDITEM;
class CDDDbUNS;
class CDDDbUNSRECORDITEM;

/**
 * @brief element RECORD
 *
 */
class VECTOR_CDD_API CDDDbRECORDImpl
{
public:
    CDDDbRECORDImpl();
    ~CDDDbRECORDImpl();

    void load(const QDomElement &element);

    /** @attribute id */
    QString m_id;

    /** @attribute oid */
    QString m_oid;

    /** @attribute v */
    QString m_v;

    QString m_text;

    /** @element CSTR */
    QVector<QSharedPointer<CDDDbCSTR>> m_elCstrs;

    /** @element ENUM */
    QVector<QSharedPointer<CDDDbENUM>> m_elEnums;

    /** @element ENUMRECORDITEM */
    QVector<QSharedPointer<CDDDbENUMRECORDITEM>> m_elEnumrecorditems;

    /** @element TEXT */
    QSharedPointer<CDDDbTEXT> m_elText;

    /** @element TRRECORDITEM */
    QVector<QSharedPointer<CDDDbTRRECORDITEM>> m_elTrrecorditems;

    /** @element UNS */
    QVector<QSharedPointer<CDDDbUNS>> m_elUnss;

    /** @element UNSRECORDITEM */
    QVector<QSharedPointer<CDDDbUNSRECORDITEM>> m_elUnsrecorditems;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBRECORDIMPL_H

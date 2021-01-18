#ifndef VECTOR_CDD_CDDDBATTRCATIMPL_H
#define VECTOR_CDD_CDDDBATTRCATIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbDESC;
class CDDDbNAME;
class CDDDbQUAL;

/**
 * @brief element ATTRCAT
 *
 */
class VECTOR_CDD_API CDDDbATTRCATImpl
{
public:
    CDDDbATTRCATImpl();
    ~CDDDbATTRCATImpl();

    void load(const QDomElement &element);

    /** @attribute id */
    QString m_id;

    /** @attribute oid */
    QString m_oid;

    /** @attribute temploid */
    QString m_temploid;

    /** @attribute usage */
    QString m_usage;

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

#endif // VECTOR_CDD_CDDDBATTRCATIMPL_H

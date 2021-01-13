#ifndef VECTOR_CDD_CDDDBATTRCAT_H
#define VECTOR_CDD_CDDDBATTRCAT_H

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
class VECTOR_CDD_API CDDDbATTRCAT
{
public:
    CDDDbATTRCAT();
    ~CDDDbATTRCAT();

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

    /** @element DESC */
    QSharedPointer<CDDDbDESC> m_desc;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_name;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_qual;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBATTRCAT_H

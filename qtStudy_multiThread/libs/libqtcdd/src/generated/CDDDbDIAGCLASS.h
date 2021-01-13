#ifndef VECTOR_CDD_CDDDBDIAGCLASS_H
#define VECTOR_CDD_CDDDBDIAGCLASS_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbDESC;
class CDDDbDIAGINST;
class CDDDbNAME;
class CDDDbQUAL;

/**
 * @brief element DIAGCLASS
 *
 */
class VECTOR_CDD_API CDDDbDIAGCLASS
{
public:
    CDDDbDIAGCLASS();
    ~CDDDbDIAGCLASS();

    void load(const QDomElement &element);

    /** @attribute id */
    QString m_id;

    /** @attribute oid */
    QString m_oid;

    /** @attribute temploid */
    QString m_temploid;

    /** @attribute tmplref */
    QString m_tmplref;

    /** @element DESC */
    QSharedPointer<CDDDbDESC> m_desc;

    /** @element DIAGINST */
    QMap<QString, QSharedPointer<CDDDbDIAGINST>> m_diaginsts;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_name;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_qual;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDIAGCLASS_H

#ifndef VECTOR_CDD_CDDDBDIAGINST_H
#define VECTOR_CDD_CDDDBDIAGINST_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbNAME;
class CDDDbQUAL;
class CDDDbSERVICE;
class CDDDbSIMPLECOMPCONT;
class CDDDbSTATICVALUE;

/**
 * @brief element DIAGINST
 *
 */
class VECTOR_CDD_API CDDDbDIAGINST
{
public:
    CDDDbDIAGINST();
    ~CDDDbDIAGINST();

    void load(const QDomElement &element);

    /** @attribute id */
    QString m_id;

    /** @attribute oid */
    QString m_oid;

    /** @attribute req */
    QString m_req;

    /** @attribute temploid */
    QString m_temploid;

    /** @attribute tmplref */
    QString m_tmplref;

    /** @attribute xauth */
    QString m_xauth;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_name;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_qual;

    /** @element SERVICE */
    QMap<QString, QSharedPointer<CDDDbSERVICE>> m_services;

    /** @element SIMPLECOMPCONT */
    QVector<QSharedPointer<CDDDbSIMPLECOMPCONT>> m_simplecompconts;

    /** @element STATICVALUE */
    QSharedPointer<CDDDbSTATICVALUE> m_staticvalue;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDIAGINST_H

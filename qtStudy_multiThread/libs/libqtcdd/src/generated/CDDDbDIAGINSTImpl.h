#ifndef VECTOR_CDD_CDDDBDIAGINSTIMPL_H
#define VECTOR_CDD_CDDDBDIAGINSTIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbDESC;
class CDDDbNAME;
class CDDDbQUAL;
class CDDDbSERVICE;
class CDDDbSIMPLECOMPCONT;
class CDDDbSTATICVALUE;

/**
 * @brief element DIAGINST
 *
 */
class VECTOR_CDD_API CDDDbDIAGINSTImpl
{
public:
    CDDDbDIAGINSTImpl();
    ~CDDDbDIAGINSTImpl();

    void load(const QDomElement &element);

    /** @attribute act */
    QString m_act;

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

    QString m_text;

    /** @element DESC */
    QSharedPointer<CDDDbDESC> m_elDesc;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_elName;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_elQual;

    /** @element SERVICE */
    QMap<QString, QSharedPointer<CDDDbSERVICE>> m_elServices;

    /** @element SIMPLECOMPCONT */
    QVector<QSharedPointer<CDDDbSIMPLECOMPCONT>> m_elSimplecompconts;

    /** @element STATICVALUE */
    QSharedPointer<CDDDbSTATICVALUE> m_elStaticvalue;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDIAGINSTIMPL_H

#ifndef VECTOR_CDD_CDDDBDIAGCLASSIMPL_H
#define VECTOR_CDD_CDDDBDIAGCLASSIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbDESC;
class CDDDbDIAGINST;
class CDDDbDIAGINSTREF;
class CDDDbNAME;
class CDDDbQUAL;

/**
 * @brief element DIAGCLASS
 *
 */
class VECTOR_CDD_API CDDDbDIAGCLASSImpl
{
public:
    CDDDbDIAGCLASSImpl();
    ~CDDDbDIAGCLASSImpl();

    void load(const QDomElement &element);

    /** @attribute id */
    QString m_id;

    /** @attribute oid */
    QString m_oid;

    /** @attribute temploid */
    QString m_temploid;

    /** @attribute tmplref */
    QString m_tmplref;

    QString m_text;

    /** @element DESC */
    QSharedPointer<CDDDbDESC> m_elDesc;

    /** @element DIAGINST */
    QMap<QString, QSharedPointer<CDDDbDIAGINST>> m_elDiaginsts;

    /** @element DIAGINSTREF */
    QVector<QSharedPointer<CDDDbDIAGINSTREF>> m_elDiaginstrefs;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_elName;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_elQual;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDIAGCLASSIMPL_H

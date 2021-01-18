#ifndef VECTOR_CDD_CDDDBSERVICEIMPL_H
#define VECTOR_CDD_CDDDBSERVICEIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbENUM;
class CDDDbNAME;
class CDDDbQUAL;
class CDDDbSHORTCUTNAME;
class CDDDbSHORTCUTQUAL;

/**
 * @brief element SERVICE
 *
 */
class VECTOR_CDD_API CDDDbSERVICEImpl
{
public:
    CDDDbSERVICEImpl();
    ~CDDDbSERVICEImpl();

    void load(const QDomElement &element);

    /** @attribute func */
    QString m_func;

    /** @attribute id */
    QString m_id;

    /** @attribute mayBeExec */
    QString m_mayBeExec;

    /** @attribute oid */
    QString m_oid;

    /** @attribute phys */
    QString m_phys;

    /** @attribute req */
    QString m_req;

    /** @attribute respOnFunc */
    QString m_respOnFunc;

    /** @attribute respOnPhys */
    QString m_respOnPhys;

    /** @attribute temploid */
    QString m_temploid;

    /** @attribute tmplref */
    QString m_tmplref;

    /** @attribute trans */
    QString m_trans;

    QString m_text;

    /** @element ENUM */
    QVector<QSharedPointer<CDDDbENUM>> m_elEnums;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_elName;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_elQual;

    /** @element SHORTCUTNAME */
    QSharedPointer<CDDDbSHORTCUTNAME> m_elShortcutname;

    /** @element SHORTCUTQUAL */
    QSharedPointer<CDDDbSHORTCUTQUAL> m_elShortcutqual;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSERVICEIMPL_H

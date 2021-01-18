#ifndef VECTOR_CDD_CDDDBSGNDEFIMPL_H
#define VECTOR_CDD_CDDDBSGNDEFIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbNAME;
class CDDDbQUAL;

/**
 * @brief element SGNDEF
 *
 */
class VECTOR_CDD_API CDDDbSGNDEFImpl
{
public:
    CDDDbSGNDEFImpl();
    ~CDDDbSGNDEFImpl();

    void load(const QDomElement &element);

    /** @attribute attrcatref */
    QString m_attrcatref;

    /** @attribute id */
    QString m_id;

    /** @attribute oid */
    QString m_oid;

    /** @attribute temploid */
    QString m_temploid;

    /** @attribute v */
    QString m_v;

    QString m_text;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_elName;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_elQual;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSGNDEFIMPL_H

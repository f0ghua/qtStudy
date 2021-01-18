#ifndef VECTOR_CDD_CDDDBSTRDEFIMPL_H
#define VECTOR_CDD_CDDDBSTRDEFIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbDESC;
class CDDDbNAME;
class CDDDbQUAL;
class CDDDbSTRING;

/**
 * @brief element STRDEF
 *
 */
class VECTOR_CDD_API CDDDbSTRDEFImpl
{
public:
    CDDDbSTRDEFImpl();
    ~CDDDbSTRDEFImpl();

    void load(const QDomElement &element);

    /** @attribute attrcatref */
    QString m_attrcatref;

    /** @attribute id */
    QString m_id;

    /** @attribute mayBeReported */
    QString m_mayBeReported;

    /** @attribute oid */
    QString m_oid;

    /** @attribute temploid */
    QString m_temploid;

    /** @attribute xauth */
    QString m_xauth;

    QString m_text;

    /** @element DESC */
    QSharedPointer<CDDDbDESC> m_elDesc;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_elName;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_elQual;

    /** @element STRING */
    QSharedPointer<CDDDbSTRING> m_elString;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSTRDEFIMPL_H

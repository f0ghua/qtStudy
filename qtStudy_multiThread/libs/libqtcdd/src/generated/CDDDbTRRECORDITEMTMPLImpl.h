#ifndef VECTOR_CDD_CDDDBTRRECORDITEMTMPLIMPL_H
#define VECTOR_CDD_CDDDBTRRECORDITEMTMPLIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbCHOICE;
class CDDDbDEFAULT;
class CDDDbDESC;
class CDDDbNAME;
class CDDDbQUAL;

/**
 * @brief element TRRECORDITEMTMPL
 *
 */
class VECTOR_CDD_API CDDDbTRRECORDITEMTMPLImpl
{
public:
    CDDDbTRRECORDITEMTMPLImpl();
    ~CDDDbTRRECORDITEMTMPLImpl();

    void load(const QDomElement &element);

    /** @attribute conv */
    QString m_conv;

    /** @attribute id */
    QString m_id;

    /** @attribute mayBeDup */
    QString m_mayBeDup;

    /** @attribute oid */
    QString m_oid;

    /** @attribute temploid */
    QString m_temploid;

    QString m_text;

    /** @element CHOICE */
    QVector<QSharedPointer<CDDDbCHOICE>> m_elChoices;

    /** @element DEFAULT */
    QSharedPointer<CDDDbDEFAULT> m_elDefault;

    /** @element DESC */
    QSharedPointer<CDDDbDESC> m_elDesc;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_elName;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_elQual;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBTRRECORDITEMTMPLIMPL_H

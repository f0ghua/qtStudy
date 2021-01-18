#ifndef VECTOR_CDD_CDDDBIDENTIMPL_H
#define VECTOR_CDD_CDDDBIDENTIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbCVALUETYPE;
class CDDDbDESC;
class CDDDbENUM;
class CDDDbEXCL;
class CDDDbNAME;
class CDDDbPVALUETYPE;
class CDDDbQUAL;

/**
 * @brief element IDENT
 *
 */
class VECTOR_CDD_API CDDDbIDENTImpl
{
public:
    CDDDbIDENTImpl();
    ~CDDDbIDENTImpl();

    void load(const QDomElement &element);

    /** @attribute bm */
    QString m_bm;

    /** @attribute id */
    QString m_id;

    /** @attribute oid */
    QString m_oid;

    /** @attribute temploid */
    QString m_temploid;

    /** @attribute xauth */
    QString m_xauth;

    QString m_text;

    /** @element CVALUETYPE */
    QSharedPointer<CDDDbCVALUETYPE> m_elCvaluetype;

    /** @element DESC */
    QSharedPointer<CDDDbDESC> m_elDesc;

    /** @element ENUM */
    QVector<QSharedPointer<CDDDbENUM>> m_elEnums;

    /** @element EXCL */
    QVector<QSharedPointer<CDDDbEXCL>> m_elExcls;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_elName;

    /** @element PVALUETYPE */
    QSharedPointer<CDDDbPVALUETYPE> m_elPvaluetype;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_elQual;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBIDENTIMPL_H

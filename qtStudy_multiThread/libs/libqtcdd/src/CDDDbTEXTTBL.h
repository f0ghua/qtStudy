#ifndef VECTOR_CDD_CDDDBTEXTTBL_H
#define VECTOR_CDD_CDDDBTEXTTBL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbCVALUETYPE;
class CDDDbNAME;
class CDDDbPVALUETYPE;
class CDDDbQUAL;
class CDDDbTEXTMAP;

/**
 * @brief element TEXTTBL
 *
 */
class VECTOR_CDD_API CDDDbTEXTTBL
{
public:
    CDDDbTEXTTBL();
    ~CDDDbTEXTTBL();

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

    /** @element CVALUETYPE */
    QSharedPointer<CDDDbCVALUETYPE> m_cvaluetype;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_name;

    /** @element PVALUETYPE */
    QSharedPointer<CDDDbPVALUETYPE> m_pvaluetype;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_qual;

    /** @element TEXTMAP */
    QVector<QSharedPointer<CDDDbTEXTMAP>> m_textmaps;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBTEXTTBL_H

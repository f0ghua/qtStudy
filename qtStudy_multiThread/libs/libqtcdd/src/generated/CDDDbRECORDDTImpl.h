#ifndef VECTOR_CDD_CDDDBRECORDDTIMPL_H
#define VECTOR_CDD_CDDDBRECORDDTIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbCVALUETYPE;
class CDDDbNAME;
class CDDDbPVALUETYPE;
class CDDDbQUAL;
class CDDDbRECORD;

/**
 * @brief element RECORDDT
 *
 */
class VECTOR_CDD_API CDDDbRECORDDTImpl
{
public:
    CDDDbRECORDDTImpl();
    ~CDDDbRECORDDTImpl();

    void load(const QDomElement &element);

    /** @attribute bm */
    QString m_bm;

    /** @attribute id */
    QString m_id;

    /** @attribute oid */
    QString m_oid;

    /** @attribute rtSpec */
    QString m_rtSpec;

    /** @attribute temploid */
    QString m_temploid;

    QString m_text;

    /** @element CVALUETYPE */
    QSharedPointer<CDDDbCVALUETYPE> m_elCvaluetype;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_elName;

    /** @element PVALUETYPE */
    QSharedPointer<CDDDbPVALUETYPE> m_elPvaluetype;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_elQual;

    /** @element RECORD */
    QMap<QString, QSharedPointer<CDDDbRECORD>> m_elRecords;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBRECORDDTIMPL_H

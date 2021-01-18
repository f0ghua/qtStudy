#ifndef VECTOR_CDD_CDDDBRECORDDATAOBJIMPL_H
#define VECTOR_CDD_CDDDBRECORDDATAOBJIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbNAME;
class CDDDbQUAL;
class CDDDbRECORDDT;

/**
 * @brief element RECORDDATAOBJ
 *
 */
class VECTOR_CDD_API CDDDbRECORDDATAOBJImpl
{
public:
    CDDDbRECORDDATAOBJImpl();
    ~CDDDbRECORDDATAOBJImpl();

    void load(const QDomElement &element);

    /** @attribute oid */
    QString m_oid;

    /** @attribute rtSpec */
    QString m_rtSpec;

    /** @attribute temploid */
    QString m_temploid;

    QString m_text;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_elName;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_elQual;

    /** @element RECORDDT */
    QMap<QString, QSharedPointer<CDDDbRECORDDT>> m_elRecorddts;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBRECORDDATAOBJIMPL_H

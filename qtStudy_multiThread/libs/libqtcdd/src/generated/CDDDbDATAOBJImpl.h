#ifndef VECTOR_CDD_CDDDBDATAOBJIMPL_H
#define VECTOR_CDD_CDDDBDATAOBJIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbDESC;
class CDDDbNAME;
class CDDDbQUAL;

/**
 * @brief element DATAOBJ
 *
 */
class VECTOR_CDD_API CDDDbDATAOBJImpl
{
public:
    CDDDbDATAOBJImpl();
    ~CDDDbDATAOBJImpl();

    void load(const QDomElement &element);

    /** @attribute dataObjectRef */
    QString m_dataObjectRef;

    /** @attribute def */
    QString m_def;

    /** @attribute dtref */
    QString m_dtref;

    /** @attribute id */
    QString m_id;

    /** @attribute oid */
    QString m_oid;

    /** @attribute spec */
    QString m_spec;

    /** @attribute temploid */
    QString m_temploid;

    /** @attribute v */
    QString m_v;

    QString m_text;

    /** @element DESC */
    QSharedPointer<CDDDbDESC> m_elDesc;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_elName;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_elQual;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDATAOBJIMPL_H

#ifndef VECTOR_CDD_CDDDBSTRUCTIMPL_H
#define VECTOR_CDD_CDDDBSTRUCTIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbDATAOBJ;
class CDDDbGAPDATAOBJ;
class CDDDbNAME;
class CDDDbQUAL;

/**
 * @brief element STRUCT
 *
 */
class VECTOR_CDD_API CDDDbSTRUCTImpl
{
public:
    CDDDbSTRUCTImpl();
    ~CDDDbSTRUCTImpl();

    void load(const QDomElement &element);

    /** @attribute dtref */
    QString m_dtref;

    /** @attribute oid */
    QString m_oid;

    /** @attribute spec */
    QString m_spec;

    /** @attribute temploid */
    QString m_temploid;

    QString m_text;

    /** @element DATAOBJ */
    QMap<QString, QSharedPointer<CDDDbDATAOBJ>> m_elDataobjs;

    /** @element GAPDATAOBJ */
    QVector<QSharedPointer<CDDDbGAPDATAOBJ>> m_elGapdataobjs;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_elName;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_elQual;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSTRUCTIMPL_H

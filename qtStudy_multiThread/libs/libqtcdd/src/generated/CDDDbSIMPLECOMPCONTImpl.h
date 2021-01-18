#ifndef VECTOR_CDD_CDDDBSIMPLECOMPCONTIMPL_H
#define VECTOR_CDD_CDDDBSIMPLECOMPCONTIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbDATAOBJ;
class CDDDbDIDDATAREF;
class CDDDbGODTCDATAOBJ;
class CDDDbRECORDDATAOBJ;
class CDDDbSPECDATAOBJ;
class CDDDbSTRUCT;

/**
 * @brief element SIMPLECOMPCONT
 *
 */
class VECTOR_CDD_API CDDDbSIMPLECOMPCONTImpl
{
public:
    CDDDbSIMPLECOMPCONTImpl();
    ~CDDDbSIMPLECOMPCONTImpl();

    void load(const QDomElement &element);

    /** @attribute oid */
    QString m_oid;

    /** @attribute shproxyref */
    QString m_shproxyref;

    /** @attribute temploid */
    QString m_temploid;

    QString m_text;

    /** @element DATAOBJ */
    QMap<QString, QSharedPointer<CDDDbDATAOBJ>> m_elDataobjs;

    /** @element DIDDATAREF */
    QSharedPointer<CDDDbDIDDATAREF> m_elDiddataref;

    /** @element GODTCDATAOBJ */
    QSharedPointer<CDDDbGODTCDATAOBJ> m_elGodtcdataobj;

    /** @element RECORDDATAOBJ */
    QSharedPointer<CDDDbRECORDDATAOBJ> m_elRecorddataobj;

    /** @element SPECDATAOBJ */
    QSharedPointer<CDDDbSPECDATAOBJ> m_elSpecdataobj;

    /** @element STRUCT */
    QVector<QSharedPointer<CDDDbSTRUCT>> m_elStructs;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSIMPLECOMPCONTIMPL_H

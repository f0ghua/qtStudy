#ifndef VECTOR_CDD_CDDDBSPECIFICSNAPSHOTRECORDIMPL_H
#define VECTOR_CDD_CDDDBSPECIFICSNAPSHOTRECORDIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbNAME;
class CDDDbQUAL;

/**
 * @brief element SPECIFICSNAPSHOTRECORD
 *
 */
class VECTOR_CDD_API CDDDbSPECIFICSNAPSHOTRECORDImpl
{
public:
    CDDDbSPECIFICSNAPSHOTRECORDImpl();
    ~CDDDbSPECIFICSNAPSHOTRECORDImpl();

    void load(const QDomElement &element);

    /** @attribute csdRef */
    QString m_csdRef;

    /** @attribute mayBeDel */
    QString m_mayBeDel;

    /** @attribute mayBeMod */
    QString m_mayBeMod;

    /** @attribute mayBeModData */
    QString m_mayBeModData;

    /** @attribute oid */
    QString m_oid;

    /** @attribute rn */
    QString m_rn;

    /** @attribute temploid */
    QString m_temploid;

    QString m_text;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_elName;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_elQual;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSPECIFICSNAPSHOTRECORDIMPL_H

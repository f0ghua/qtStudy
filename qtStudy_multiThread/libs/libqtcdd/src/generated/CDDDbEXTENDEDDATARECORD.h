#ifndef VECTOR_CDD_CDDDBEXTENDEDDATARECORD_H
#define VECTOR_CDD_CDDDBEXTENDEDDATARECORD_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbNAME;
class CDDDbQUAL;
class CDDDbSTRUCTURE;

/**
 * @brief element EXTENDEDDATARECORD
 *
 */
class VECTOR_CDD_API CDDDbEXTENDEDDATARECORD
{
public:
    CDDDbEXTENDEDDATARECORD();
    ~CDDDbEXTENDEDDATARECORD();

    void load(const QDomElement &element);

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

    /** @attribute supportEdrForDtc */
    QString m_supportEdrForDtc;

    /** @attribute temploid */
    QString m_temploid;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_name;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_qual;

    /** @element STRUCTURE */
    QSharedPointer<CDDDbSTRUCTURE> m_structure;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBEXTENDEDDATARECORD_H

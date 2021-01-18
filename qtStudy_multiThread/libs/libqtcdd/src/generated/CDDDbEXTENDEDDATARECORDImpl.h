#ifndef VECTOR_CDD_CDDDBEXTENDEDDATARECORDIMPL_H
#define VECTOR_CDD_CDDDBEXTENDEDDATARECORDIMPL_H

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
class VECTOR_CDD_API CDDDbEXTENDEDDATARECORDImpl
{
public:
    CDDDbEXTENDEDDATARECORDImpl();
    ~CDDDbEXTENDEDDATARECORDImpl();

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

    QString m_text;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_elName;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_elQual;

    /** @element STRUCTURE */
    QSharedPointer<CDDDbSTRUCTURE> m_elStructure;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBEXTENDEDDATARECORDIMPL_H

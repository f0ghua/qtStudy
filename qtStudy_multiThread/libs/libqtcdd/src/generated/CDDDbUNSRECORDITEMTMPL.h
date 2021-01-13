#ifndef VECTOR_CDD_CDDDBUNSRECORDITEMTMPL_H
#define VECTOR_CDD_CDDDBUNSRECORDITEMTMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbDESC;
class CDDDbNAME;
class CDDDbQUAL;

/**
 * @brief element UNSRECORDITEMTMPL
 *
 */
class VECTOR_CDD_API CDDDbUNSRECORDITEMTMPL
{
public:
    CDDDbUNSRECORDITEMTMPL();
    ~CDDDbUNSRECORDITEMTMPL();

    void load(const QDomElement &element);

    /** @attribute conv */
    QString m_conv;

    /** @attribute df */
    QString m_df;

    /** @attribute id */
    QString m_id;

    /** @attribute mayBeDup */
    QString m_mayBeDup;

    /** @attribute oid */
    QString m_oid;

    /** @attribute temploid */
    QString m_temploid;

    /** @attribute v */
    QString m_v;

    /** @element DESC */
    QSharedPointer<CDDDbDESC> m_desc;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_name;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_qual;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBUNSRECORDITEMTMPL_H

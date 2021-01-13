#ifndef VECTOR_CDD_CDDDBUNSDEF_H
#define VECTOR_CDD_CDDDBUNSDEF_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbNAME;
class CDDDbQUAL;

/**
 * @brief element UNSDEF
 *
 */
class VECTOR_CDD_API CDDDbUNSDEF
{
public:
    CDDDbUNSDEF();
    ~CDDDbUNSDEF();

    void load(const QDomElement &element);

    /** @attribute attrcatref */
    QString m_attrcatref;

    /** @attribute df */
    QString m_df;

    /** @attribute id */
    QString m_id;

    /** @attribute oid */
    QString m_oid;

    /** @attribute temploid */
    QString m_temploid;

    /** @attribute v */
    QString m_v;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_name;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_qual;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBUNSDEF_H

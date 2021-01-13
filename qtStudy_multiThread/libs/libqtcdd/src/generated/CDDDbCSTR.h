#ifndef VECTOR_CDD_CDDDBCSTR_H
#define VECTOR_CDD_CDDDBCSTR_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbCOMMONSTRING;

/**
 * @brief element CSTR
 *
 */
class VECTOR_CDD_API CDDDbCSTR
{
public:
    CDDDbCSTR();
    ~CDDDbCSTR();

    void load(const QDomElement &element);

    /** @attribute attrref */
    QString m_attrref;

    /** @attribute oid */
    QString m_oid;

    /** @attribute temploid */
    QString m_temploid;

    /** @element COMMONSTRING */
    QSharedPointer<CDDDbCOMMONSTRING> m_commonstring;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBCSTR_H

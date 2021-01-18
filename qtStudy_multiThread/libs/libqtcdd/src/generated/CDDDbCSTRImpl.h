#ifndef VECTOR_CDD_CDDDBCSTRIMPL_H
#define VECTOR_CDD_CDDDBCSTRIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbCOMMONSTRING;

/**
 * @brief element CSTR
 *
 */
class VECTOR_CDD_API CDDDbCSTRImpl
{
public:
    CDDDbCSTRImpl();
    ~CDDDbCSTRImpl();

    void load(const QDomElement &element);

    /** @attribute attrref */
    QString m_attrref;

    /** @attribute oid */
    QString m_oid;

    /** @attribute temploid */
    QString m_temploid;

    QString m_text;

    /** @element COMMONSTRING */
    QSharedPointer<CDDDbCOMMONSTRING> m_elCommonstring;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBCSTRIMPL_H

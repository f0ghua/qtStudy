#ifndef VECTOR_CDD_CDDDBUNSIMPL_H
#define VECTOR_CDD_CDDDBUNSIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {


/**
 * @brief element UNS
 *
 */
class VECTOR_CDD_API CDDDbUNSImpl
{
public:
    CDDDbUNSImpl();
    ~CDDDbUNSImpl();

    void load(const QDomElement &element);

    /** @attribute attrref */
    QString m_attrref;

    /** @attribute oid */
    QString m_oid;

    /** @attribute temploid */
    QString m_temploid;

    /** @attribute v */
    QString m_v;

    QString m_text;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBUNSIMPL_H

#ifndef VECTOR_CDD_CDDDBUNSRECORDITEM_H
#define VECTOR_CDD_CDDDBUNSRECORDITEM_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {


/**
 * @brief element UNSRECORDITEM
 *
 */
class VECTOR_CDD_API CDDDbUNSRECORDITEM
{
public:
    CDDDbUNSRECORDITEM();
    ~CDDDbUNSRECORDITEM();

    void load(const QDomElement &element);

    /** @attribute idref */
    QString m_idref;

    /** @attribute v */
    QString m_v;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBUNSRECORDITEM_H

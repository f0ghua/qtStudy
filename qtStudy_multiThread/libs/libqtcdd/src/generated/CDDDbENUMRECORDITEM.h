#ifndef VECTOR_CDD_CDDDBENUMRECORDITEM_H
#define VECTOR_CDD_CDDDBENUMRECORDITEM_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {


/**
 * @brief element ENUMRECORDITEM
 *
 */
class VECTOR_CDD_API CDDDbENUMRECORDITEM
{
public:
    CDDDbENUMRECORDITEM();
    ~CDDDbENUMRECORDITEM();

    void load(const QDomElement &element);

    /** @attribute idref */
    QString m_idref;

    /** @attribute v */
    QString m_v;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBENUMRECORDITEM_H

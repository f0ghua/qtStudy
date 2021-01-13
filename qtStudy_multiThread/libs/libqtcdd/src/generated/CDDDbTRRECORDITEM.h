#ifndef VECTOR_CDD_CDDDBTRRECORDITEM_H
#define VECTOR_CDD_CDDDBTRRECORDITEM_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbTEXT;

/**
 * @brief element TRRECORDITEM
 *
 */
class VECTOR_CDD_API CDDDbTRRECORDITEM
{
public:
    CDDDbTRRECORDITEM();
    ~CDDDbTRRECORDITEM();

    void load(const QDomElement &element);

    /** @attribute idref */
    QString m_idref;

    /** @element TEXT */
    QSharedPointer<CDDDbTEXT> m_text;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBTRRECORDITEM_H

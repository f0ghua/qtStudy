#ifndef VECTOR_CDD_CDDDBTRRECORDITEMIMPL_H
#define VECTOR_CDD_CDDDBTRRECORDITEMIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbTEXT;

/**
 * @brief element TRRECORDITEM
 *
 */
class VECTOR_CDD_API CDDDbTRRECORDITEMImpl
{
public:
    CDDDbTRRECORDITEMImpl();
    ~CDDDbTRRECORDITEMImpl();

    void load(const QDomElement &element);

    /** @attribute idref */
    QString m_idref;

    QString m_text;

    /** @element TEXT */
    QSharedPointer<CDDDbTEXT> m_elText;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBTRRECORDITEMIMPL_H

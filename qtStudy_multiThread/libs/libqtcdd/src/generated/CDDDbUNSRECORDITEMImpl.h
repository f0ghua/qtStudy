#ifndef VECTOR_CDD_CDDDBUNSRECORDITEMIMPL_H
#define VECTOR_CDD_CDDDBUNSRECORDITEMIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {


/**
 * @brief element UNSRECORDITEM
 *
 */
class VECTOR_CDD_API CDDDbUNSRECORDITEMImpl
{
public:
    CDDDbUNSRECORDITEMImpl();
    ~CDDDbUNSRECORDITEMImpl();

    void load(const QDomElement &element);

    /** @attribute idref */
    QString m_idref;

    /** @attribute v */
    QString m_v;

    QString m_text;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBUNSRECORDITEMIMPL_H

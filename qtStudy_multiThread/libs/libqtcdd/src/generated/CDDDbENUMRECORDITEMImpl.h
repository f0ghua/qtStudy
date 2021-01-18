#ifndef VECTOR_CDD_CDDDBENUMRECORDITEMIMPL_H
#define VECTOR_CDD_CDDDBENUMRECORDITEMIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {


/**
 * @brief element ENUMRECORDITEM
 *
 */
class VECTOR_CDD_API CDDDbENUMRECORDITEMImpl
{
public:
    CDDDbENUMRECORDITEMImpl();
    ~CDDDbENUMRECORDITEMImpl();

    void load(const QDomElement &element);

    /** @attribute idref */
    QString m_idref;

    /** @attribute v */
    QString m_v;

    QString m_text;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBENUMRECORDITEMIMPL_H

#ifndef VECTOR_CDD_CDDDBJOBCNRREFIMPL_H
#define VECTOR_CDD_CDDDBJOBCNRREFIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {


/**
 * @brief element JOBCNRREF
 *
 */
class VECTOR_CDD_API CDDDbJOBCNRREFImpl
{
public:
    CDDDbJOBCNRREFImpl();
    ~CDDDbJOBCNRREFImpl();

    void load(const QDomElement &element);

    /** @attribute idref */
    QString m_idref;

    QString m_text;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBJOBCNRREFIMPL_H

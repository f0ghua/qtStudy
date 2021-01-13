#ifndef VECTOR_CDD_CDDDBJOBCNRREF_H
#define VECTOR_CDD_CDDDBJOBCNRREF_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {


/**
 * @brief element JOBCNRREF
 *
 */
class VECTOR_CDD_API CDDDbJOBCNRREF
{
public:
    CDDDbJOBCNRREF();
    ~CDDDbJOBCNRREF();

    void load(const QDomElement &element);

    /** @attribute idref */
    QString m_idref;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBJOBCNRREF_H

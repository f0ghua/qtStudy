#ifndef VECTOR_CDD_CDDDBJOBCNRREF_H
#define VECTOR_CDD_CDDDBJOBCNRREF_H

#include "CDDDbJOBCNRREFImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element JOBCNRREF
 *
 */
class VECTOR_CDD_API CDDDbJOBCNRREF : public CDDDbJOBCNRREFImpl
{
public:
    CDDDbJOBCNRREF();
    ~CDDDbJOBCNRREF();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBJOBCNRREF_H

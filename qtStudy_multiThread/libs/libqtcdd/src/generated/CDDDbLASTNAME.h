#ifndef VECTOR_CDD_CDDDBLASTNAME_H
#define VECTOR_CDD_CDDDBLASTNAME_H

#include "CDDDbLASTNAMEImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element LASTNAME
 *
 */
class VECTOR_CDD_API CDDDbLASTNAME : public CDDDbLASTNAMEImpl
{
public:
    CDDDbLASTNAME();
    ~CDDDbLASTNAME();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBLASTNAME_H

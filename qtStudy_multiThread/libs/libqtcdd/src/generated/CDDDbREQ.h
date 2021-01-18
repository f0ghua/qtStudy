#ifndef VECTOR_CDD_CDDDBREQ_H
#define VECTOR_CDD_CDDDBREQ_H

#include "CDDDbREQImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element REQ
 *
 */
class VECTOR_CDD_API CDDDbREQ : public CDDDbREQImpl
{
public:
    CDDDbREQ();
    ~CDDDbREQ();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBREQ_H

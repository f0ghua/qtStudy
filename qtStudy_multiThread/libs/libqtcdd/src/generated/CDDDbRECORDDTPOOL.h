#ifndef VECTOR_CDD_CDDDBRECORDDTPOOL_H
#define VECTOR_CDD_CDDDBRECORDDTPOOL_H

#include "CDDDbRECORDDTPOOLImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element RECORDDTPOOL
 *
 */
class VECTOR_CDD_API CDDDbRECORDDTPOOL : public CDDDbRECORDDTPOOLImpl
{
public:
    CDDDbRECORDDTPOOL();
    ~CDDDbRECORDDTPOOL();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBRECORDDTPOOL_H

#ifndef VECTOR_CDD_CDDDBDIAGINST_H
#define VECTOR_CDD_CDDDBDIAGINST_H

#include "CDDDbDIAGINSTImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element DIAGINST
 *
 */
class VECTOR_CDD_API CDDDbDIAGINST : public CDDDbDIAGINSTImpl
{
public:
    CDDDbDIAGINST();
    ~CDDDbDIAGINST();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDIAGINST_H

#ifndef VECTOR_CDD_CDDDBATTRCAT_H
#define VECTOR_CDD_CDDDBATTRCAT_H

#include "CDDDbATTRCATImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element ATTRCAT
 *
 */
class VECTOR_CDD_API CDDDbATTRCAT : public CDDDbATTRCATImpl
{
public:
    CDDDbATTRCAT();
    ~CDDDbATTRCAT();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBATTRCAT_H

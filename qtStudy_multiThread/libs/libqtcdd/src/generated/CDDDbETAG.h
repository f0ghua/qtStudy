#ifndef VECTOR_CDD_CDDDBETAG_H
#define VECTOR_CDD_CDDDBETAG_H

#include "CDDDbETAGImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element ETAG
 *
 */
class VECTOR_CDD_API CDDDbETAG : public CDDDbETAGImpl
{
public:
    CDDDbETAG();
    ~CDDDbETAG();

    void load(const QDomElement &element);

public:
    QString getValue() const;
};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBETAG_H

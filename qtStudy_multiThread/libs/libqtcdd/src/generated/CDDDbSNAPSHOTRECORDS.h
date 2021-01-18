#ifndef VECTOR_CDD_CDDDBSNAPSHOTRECORDS_H
#define VECTOR_CDD_CDDDBSNAPSHOTRECORDS_H

#include "CDDDbSNAPSHOTRECORDSImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element SNAPSHOTRECORDS
 *
 */
class VECTOR_CDD_API CDDDbSNAPSHOTRECORDS : public CDDDbSNAPSHOTRECORDSImpl
{
public:
    CDDDbSNAPSHOTRECORDS();
    ~CDDDbSNAPSHOTRECORDS();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSNAPSHOTRECORDS_H

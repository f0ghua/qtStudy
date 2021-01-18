#ifndef VECTOR_CDD_CDDDBDEFATTS_H
#define VECTOR_CDD_CDDDBDEFATTS_H

#include "CDDDbDEFATTSImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element DEFATTS
 *
 */
class VECTOR_CDD_API CDDDbDEFATTS : public CDDDbDEFATTSImpl
{
public:
    CDDDbDEFATTS();
    ~CDDDbDEFATTS();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDEFATTS_H

#ifndef VECTOR_CDD_CDDDBDIAGINSTATTS_H
#define VECTOR_CDD_CDDDBDIAGINSTATTS_H

#include "CDDDbDIAGINSTATTSImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element DIAGINSTATTS
 *
 */
class VECTOR_CDD_API CDDDbDIAGINSTATTS : public CDDDbDIAGINSTATTSImpl
{
public:
    CDDDbDIAGINSTATTS();
    ~CDDDbDIAGINSTATTS();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDIAGINSTATTS_H

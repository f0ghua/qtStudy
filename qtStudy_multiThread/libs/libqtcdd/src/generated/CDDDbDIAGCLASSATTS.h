#ifndef VECTOR_CDD_CDDDBDIAGCLASSATTS_H
#define VECTOR_CDD_CDDDBDIAGCLASSATTS_H

#include "CDDDbDIAGCLASSATTSImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element DIAGCLASSATTS
 *
 */
class VECTOR_CDD_API CDDDbDIAGCLASSATTS : public CDDDbDIAGCLASSATTSImpl
{
public:
    CDDDbDIAGCLASSATTS();
    ~CDDDbDIAGCLASSATTS();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDIAGCLASSATTS_H

#ifndef VECTOR_CDD_CDDDBSHORTCUTNAME_H
#define VECTOR_CDD_CDDDBSHORTCUTNAME_H

#include "CDDDbSHORTCUTNAMEImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element SHORTCUTNAME
 *
 */
class VECTOR_CDD_API CDDDbSHORTCUTNAME : public CDDDbSHORTCUTNAMEImpl
{
public:
    CDDDbSHORTCUTNAME();
    ~CDDDbSHORTCUTNAME();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSHORTCUTNAME_H

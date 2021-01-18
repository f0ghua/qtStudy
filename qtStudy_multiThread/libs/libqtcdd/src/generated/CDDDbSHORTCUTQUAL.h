#ifndef VECTOR_CDD_CDDDBSHORTCUTQUAL_H
#define VECTOR_CDD_CDDDBSHORTCUTQUAL_H

#include "CDDDbSHORTCUTQUALImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element SHORTCUTQUAL
 *
 */
class VECTOR_CDD_API CDDDbSHORTCUTQUAL : public CDDDbSHORTCUTQUALImpl
{
public:
    CDDDbSHORTCUTQUAL();
    ~CDDDbSHORTCUTQUAL();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSHORTCUTQUAL_H

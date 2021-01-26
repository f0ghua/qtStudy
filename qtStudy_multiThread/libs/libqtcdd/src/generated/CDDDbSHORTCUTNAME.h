#ifndef VECTOR_CDD_CDDDBSHORTCUTNAME_H
#define VECTOR_CDD_CDDDBSHORTCUTNAME_H

#include "CDDDbNAME.h"

namespace vector {
namespace cdd {

/**
 * @brief element SHORTCUTNAME
 *
 */
class VECTOR_CDD_API CDDDbSHORTCUTNAME : public CDDDbNAME
{
public:
    CDDDbSHORTCUTNAME();
    ~CDDDbSHORTCUTNAME();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSHORTCUTNAME_H

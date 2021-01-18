#ifndef VECTOR_CDD_CDDDBSHORTCUTQUALIMPL_H
#define VECTOR_CDD_CDDDBSHORTCUTQUALIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {


/**
 * @brief element SHORTCUTQUAL
 *
 */
class VECTOR_CDD_API CDDDbSHORTCUTQUALImpl
{
public:
    CDDDbSHORTCUTQUALImpl();
    ~CDDDbSHORTCUTQUALImpl();

    void load(const QDomElement &element);

    QString m_text;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSHORTCUTQUALIMPL_H

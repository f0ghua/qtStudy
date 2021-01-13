#ifndef VECTOR_CDD_CDDDBSHORTCUTQUAL_H
#define VECTOR_CDD_CDDDBSHORTCUTQUAL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {


/**
 * @brief element SHORTCUTQUAL
 *
 */
class VECTOR_CDD_API CDDDbSHORTCUTQUAL
{
public:
    CDDDbSHORTCUTQUAL();
    ~CDDDbSHORTCUTQUAL();

    void load(const QDomElement &element);

    QString m_text;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSHORTCUTQUAL_H

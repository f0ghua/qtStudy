#ifndef VECTOR_CDD_CDDDBTEXTMAP_H
#define VECTOR_CDD_CDDDBTEXTMAP_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbTEXT;

/**
 * @brief element TEXTMAP
 *
 */
class VECTOR_CDD_API CDDDbTEXTMAP
{
public:
    CDDDbTEXTMAP();
    ~CDDDbTEXTMAP();

    void load(const QDomElement &element);

    /** @attribute e */
    QString m_e;

    /** @attribute s */
    QString m_s;

    /** @element TEXT */
    QSharedPointer<CDDDbTEXT> m_text;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBTEXTMAP_H

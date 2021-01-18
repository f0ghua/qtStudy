#ifndef VECTOR_CDD_CDDDBEXCLIMPL_H
#define VECTOR_CDD_CDDDBEXCLIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbTEXT;

/**
 * @brief element EXCL
 *
 */
class VECTOR_CDD_API CDDDbEXCLImpl
{
public:
    CDDDbEXCLImpl();
    ~CDDDbEXCLImpl();

    void load(const QDomElement &element);

    /** @attribute e */
    QString m_e;

    /** @attribute inv */
    QString m_inv;

    /** @attribute s */
    QString m_s;

    QString m_text;

    /** @element TEXT */
    QSharedPointer<CDDDbTEXT> m_elText;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBEXCLIMPL_H

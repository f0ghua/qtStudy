#ifndef VECTOR_CDD_CDDDBAUTHORSIMPL_H
#define VECTOR_CDD_CDDDBAUTHORSIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbAUTHOR;

/**
 * @brief element AUTHORS
 *
 */
class VECTOR_CDD_API CDDDbAUTHORSImpl
{
public:
    CDDDbAUTHORSImpl();
    ~CDDDbAUTHORSImpl();

    void load(const QDomElement &element);

    QString m_text;

    /** @element AUTHOR */
    QSharedPointer<CDDDbAUTHOR> m_elAuthor;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBAUTHORSIMPL_H

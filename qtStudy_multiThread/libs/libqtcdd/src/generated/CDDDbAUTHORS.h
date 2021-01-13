#ifndef VECTOR_CDD_CDDDBAUTHORS_H
#define VECTOR_CDD_CDDDBAUTHORS_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbAUTHOR;

/**
 * @brief element AUTHORS
 *
 */
class VECTOR_CDD_API CDDDbAUTHORS
{
public:
    CDDDbAUTHORS();
    ~CDDDbAUTHORS();

    void load(const QDomElement &element);

    /** @element AUTHOR */
    QSharedPointer<CDDDbAUTHOR> m_author;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBAUTHORS_H

#ifndef VECTOR_CDD_CDDDBUNIT_H
#define VECTOR_CDD_CDDDBUNIT_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {


/**
 * @brief element UNIT
 *
 */
class VECTOR_CDD_API CDDDbUNIT
{
public:
    CDDDbUNIT();
    ~CDDDbUNIT();

    void load(const QDomElement &element);

    QString m_text;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBUNIT_H

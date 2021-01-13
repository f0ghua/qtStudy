#ifndef VECTOR_CDD_CDDDBQUAL_H
#define VECTOR_CDD_CDDDBQUAL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {


/**
 * @brief element QUAL
 *
 */
class VECTOR_CDD_API CDDDbQUAL
{
public:
    CDDDbQUAL();
    ~CDDDbQUAL();

    void load(const QDomElement &element);

    QString m_text;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBQUAL_H

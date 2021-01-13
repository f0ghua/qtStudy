#ifndef VECTOR_CDD_CDDDBMOD_H
#define VECTOR_CDD_CDDDBMOD_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {


/**
 * @brief element MOD
 *
 */
class VECTOR_CDD_API CDDDbMOD
{
public:
    CDDDbMOD();
    ~CDDDbMOD();

    void load(const QDomElement &element);

    QString m_text;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBMOD_H

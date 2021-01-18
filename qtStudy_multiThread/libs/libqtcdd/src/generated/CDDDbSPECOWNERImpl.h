#ifndef VECTOR_CDD_CDDDBSPECOWNERIMPL_H
#define VECTOR_CDD_CDDDBSPECOWNERIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {


/**
 * @brief element SPECOWNER
 *
 */
class VECTOR_CDD_API CDDDbSPECOWNERImpl
{
public:
    CDDDbSPECOWNERImpl();
    ~CDDDbSPECOWNERImpl();

    void load(const QDomElement &element);

    QString m_text;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSPECOWNERIMPL_H

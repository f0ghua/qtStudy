#ifndef VECTOR_CDD_CDDDBMODIMPL_H
#define VECTOR_CDD_CDDDBMODIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {


/**
 * @brief element MOD
 *
 */
class VECTOR_CDD_API CDDDbMODImpl
{
public:
    CDDDbMODImpl();
    ~CDDDbMODImpl();

    void load(const QDomElement &element);

    QString m_text;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBMODIMPL_H

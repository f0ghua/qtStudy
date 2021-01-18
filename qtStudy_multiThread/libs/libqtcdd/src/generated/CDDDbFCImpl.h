#ifndef VECTOR_CDD_CDDDBFCIMPL_H
#define VECTOR_CDD_CDDDBFCIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {


/**
 * @brief element FC
 *
 */
class VECTOR_CDD_API CDDDbFCImpl
{
public:
    CDDDbFCImpl();
    ~CDDDbFCImpl();

    void load(const QDomElement &element);

    /** @attribute b */
    QString m_b;

    /** @attribute fs */
    QString m_fs;

    QString m_text;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBFCIMPL_H

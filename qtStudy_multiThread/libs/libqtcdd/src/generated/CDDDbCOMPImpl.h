#ifndef VECTOR_CDD_CDDDBCOMPIMPL_H
#define VECTOR_CDD_CDDDBCOMPIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {


/**
 * @brief element COMP
 *
 */
class VECTOR_CDD_API CDDDbCOMPImpl
{
public:
    CDDDbCOMPImpl();
    ~CDDDbCOMPImpl();

    void load(const QDomElement &element);

    /** @attribute div */
    QString m_div;

    /** @attribute e */
    QString m_e;

    /** @attribute f */
    QString m_f;

    /** @attribute o */
    QString m_o;

    /** @attribute s */
    QString m_s;

    QString m_text;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBCOMPIMPL_H

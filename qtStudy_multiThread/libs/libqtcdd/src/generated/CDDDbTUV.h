#ifndef VECTOR_CDD_CDDDBTUV_H
#define VECTOR_CDD_CDDDBTUV_H

#include "CDDDbTUVImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element TUV
 *
 */
class VECTOR_CDD_API CDDDbTUV : public CDDDbTUVImpl
{
public:
    CDDDbTUV();
    ~CDDDbTUV();

    void load(const QDomElement &element);

public:
    static QString ATTR_T_LANG;
    static QString ATTR_V_ENUS;

    QString getValue() const {return m_text;}
};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBTUV_H

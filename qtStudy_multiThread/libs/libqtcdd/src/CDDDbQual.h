#pragma once

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbTuv;
/**
 * @brief element NAME
 *
 * Root element
 */
class VECTOR_CDD_API CDDDbQual
{
public:
    CDDDbQual();
    ~CDDDbQual();

    /** load from XML DOM element */
    void load(const QDomElement &element);
    QString getValue() const {return m_value;}

    QString m_value;
};

} // namespace cdd
} // namespace vector

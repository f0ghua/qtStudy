#pragma once

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbTuv;
/**
 * @brief element DESC
 *
 */
class VECTOR_CDD_API CDDDbDesc
{
public:
    CDDDbDesc();
    ~CDDDbDesc();

    /** load from XML DOM element */
    void load(const QDomElement &element);
    const QString getValue() const;

    /** element TUV */
    QMap<QString, QSharedPointer<CDDDbTuv>> m_tuvs;

};

} // namespace cdd
} // namespace vector

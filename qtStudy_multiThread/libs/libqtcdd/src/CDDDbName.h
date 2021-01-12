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
class VECTOR_CDD_API CDDDbName
{
public:
    CDDDbName();
    ~CDDDbName();

    /** load from XML DOM element */
    void load(const QDomElement &element);
    QString getValue() const;

    /** element TUV */
    QMap<QString, QSharedPointer<CDDDbTuv>> m_tuvs;

};

} // namespace cdd
} // namespace vector

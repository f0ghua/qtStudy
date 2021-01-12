#pragma once

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbTuv;
/**
 * @brief element which use TUV to define a text string
 *
 */
class VECTOR_CDD_API CDDDbTuvedType
{
public:
    CDDDbTuvedType();
    ~CDDDbTuvedType();

    /** load from XML DOM element */
    void load(const QDomElement &element);
    QString getText() const;

    /** element TUV */
    QMap<QString, QSharedPointer<CDDDbTuv>> m_tuvs;

};

} // namespace cdd
} // namespace vector

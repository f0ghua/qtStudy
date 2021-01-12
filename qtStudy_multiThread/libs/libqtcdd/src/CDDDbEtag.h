#pragma once

#include "CDDExport.h"
#include "CDDTypes.h"
#include "CDDDbTuvedType.h"

namespace vector {
namespace cdd {

/**
 * @brief element ETAG
 *
 */
class VECTOR_CDD_API CDDDbEtag : public CDDDbTuvedType
{
public:
    CDDDbEtag();
    ~CDDDbEtag();

    /** load from XML DOM element */
    void load(const QDomElement &element);
    quint32 value() const {return m_value;}
    QString text() const {return getText();}

    quint32 m_value;

};

} // namespace cdd
} // namespace vector

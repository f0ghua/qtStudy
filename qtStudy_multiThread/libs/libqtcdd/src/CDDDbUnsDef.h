#pragma once

#include "CDDExport.h"
#include "CDDTypes.h"
#include "CDDDbNamedElementType.h"
#include "CDDDbAttrCatRefType.h"

namespace vector {
namespace cdd {

/**
 * @brief element NAME
 *
 * Root element
 */
class VECTOR_CDD_API CDDDbUnsDef : public CDDDbNamedElementType, public CDDDbAttrCatRefType
{
public:
    CDDDbUnsDef();
    ~CDDDbUnsDef();

    /** load from XML DOM element */
    void load(const QDomElement &element);
    quint32 value() const {return m_value;}
    CDDUnsignedDataFormat dataFormat() const {return m_df;}

    quint32 m_value;
    CDDUnsignedDataFormat m_df;
};

} // namespace cdd
} // namespace vector

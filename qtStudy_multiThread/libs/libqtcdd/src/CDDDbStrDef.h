#pragma once

#include "CDDExport.h"
#include "CDDTypes.h"
#include "CDDDbNamedElementType.h"
#include "CDDDbAttrCatRefType.h"
#include "CDDDbTuvedType.h"

namespace vector {
namespace cdd {

/**
 * @brief element CSTRDEF
 *
 * Root element
 */
class VECTOR_CDD_API CDDDbStrDef : public CDDDbNamedElementType, public CDDDbAttrCatRefType
{
public:
    CDDDbStrDef();
    ~CDDDbStrDef();

    /** load from XML DOM element */
    void load(const QDomElement &element);
    QString string() const {return m_string.getText();}

    CDDDbTuvedType m_string;
};

} // namespace cdd
} // namespace vector

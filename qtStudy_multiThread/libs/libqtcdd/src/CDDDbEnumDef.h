#pragma once

#include "CDDExport.h"
#include "CDDTypes.h"
#include "CDDDbNamedElementType.h"
#include "CDDDbAttrCatRefType.h"

namespace vector {
namespace cdd {

class CDDDbEtag;

/**
 * @brief element ENUMDEF
 *
 */
class VECTOR_CDD_API CDDDbEnumDef : public CDDDbNamedElementType, public CDDDbAttrCatRefType
{
public:
    CDDDbEnumDef();
    ~CDDDbEnumDef();

    /** load from XML DOM element */
    void load(const QDomElement &element);
    quint32 enumValue() const {return m_value;}
    QString value() const {return m_etags.value(m_value, QString());}

    quint32 m_value{0};

    /** element ETAG */
    QMap<quint32, QString> m_etags;

};

} // namespace cdd
} // namespace vector

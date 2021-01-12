#pragma once

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbEnumDef;
class CDDDbUnsDef;
class CDDDbCstrDef;
class CDDDbStrDef;

/**
 * @brief element NAME
 *
 * Root element
 */
class VECTOR_CDD_API CDDDbECUAtts
{
public:
    CDDDbECUAtts();
    ~CDDDbECUAtts();

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /** element ENUMDEF */
    QMap<QString, QSharedPointer<CDDDbEnumDef>> m_enumdefs;

    /** element UNSDEF */
    QMap<QString, QSharedPointer<CDDDbUnsDef>> m_unsdefs;

    /** element CSTRDEF */
    QMap<QString, QSharedPointer<CDDDbCstrDef>> m_cstrdefs;

    /** element STRDEF */
    QMap<QString, QSharedPointer<CDDDbStrDef>> m_strdefs;
};

} // namespace cdd
} // namespace vector

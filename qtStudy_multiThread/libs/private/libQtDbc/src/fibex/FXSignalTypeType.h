#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

#include "FibexTypes.h"

class QDomElement;

namespace ASAM {
namespace FIBEX {

/**
 * @brief complexType SIGNAL-TYPE-TYPE
 *
 * General category (type) of a SIGNAL
 */
class VECTOR_DBC_EXPORT FXSignalTypeType
{
public:
    FXSignalTypeType();
    ~FXSignalTypeType();

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /** @required element TYPE */
    FibexTypes::FXTypeTypeSt m_type;
    /** @opt element METHOD */
    QString *m_method = nullptr;

    /** @todo element ATTRIBUTES */
    QList<QString> m_attributes;
};

} // FIBEX
} // ASAM

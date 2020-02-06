#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

#include "FXIncludedSignalType.h"

namespace ASAM {
namespace FIBEX {

/**
 * @brief complexType INCLUDED-PDU-TYPE
 *
 * SIGNALs within a referenced PDU
 */
class VECTOR_DBC_EXPORT FXIncludedPduType
{
public:
    FXIncludedPduType();

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /** element PDU-TRIGGERING-REF */
    QString m_pduTriggeringRef;
    /** element INCLUDED-SIGNALS */
    QList<FXIncludedSignalType> m_includedSignalList;
    /** element COMPLETE-PDU */
    bool m_completePdu;
    /** @todo attribute ID */
};

} // FIBEX
} // ASAM

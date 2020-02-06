#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

#include "FXIncludedPduType.h"

namespace ASAM {
namespace FIBEX {

/**
 * @brief complexType ECU-PORT-TYPE
 *
 * Content model for the entity PORT in the ECU related peculiarity.
 */
class VECTOR_DBC_EXPORT FXEcuPortType
{
public:
    FXEcuPortType();

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /** attribute ID */
    QString m_id;

    /** element ho:DESC */
    /** element FRAME-TRIGGERING-REF */
    QString m_frameTriggeringRef;
    /** element INCLUDED-PDUS */
    QList<FXIncludedPduType> m_includedPduList;
    /** element COMPLETE-FRAME */
    bool m_completeFrame;
    /** @todo element MANUFACTURER-EXTENSION */

};

} // FIBEX
} // ASAM

#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

#include "FXPduTimings.h"

namespace ASAM {
namespace FIBEX {

class FXFibex;

/**
 * @brief complexType PDU-TRIGGERING-TYPE
 *
 * Content model for the entity PDU-TRIGGERING.
 */
class VECTOR_DBC_EXPORT FXPduTriggeringType : public QObject
{
public:
    FXFibex *m_fibex = nullptr;

public:
    FXPduTriggeringType(FXFibex *fibex, QObject *parent = nullptr);

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /** @opt element TIMINGS */
    FXPduTimings *m_timings = nullptr;
    /** @must element fx:PDU-REF */
    QString m_pduRef;
    /** @todo element MANUFACTURER-EXTENSION */
    /** @must attribute ID */
    QString m_id;
};

} // FIBEX
} // ASAM

#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

#include "FXIncludedSignalType.h"

namespace ASAM {
namespace FIBEX {

class FXFibex;

/**
 * @brief complexType INCLUDED-PDU-TYPE
 *
 * SIGNALs within a referenced PDU
 */
class VECTOR_DBC_EXPORT FXIncludedPduType : public QObject
{
public:
    FXFibex *m_fibex = nullptr;

public:
    FXIncludedPduType(FXFibex *fibex, QObject *parent = nullptr);

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /** element PDU-TRIGGERING-REF */
    QString m_pduTriggeringRef;
    /** element INCLUDED-SIGNALS */
    QList<FXIncludedSignalType *> m_includedSignals;
    /** element COMPLETE-PDU */
    bool m_completePdu;
    /** @todo attribute ID */
};

} // FIBEX
} // ASAM

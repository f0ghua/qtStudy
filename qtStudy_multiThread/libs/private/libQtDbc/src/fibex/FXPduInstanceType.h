#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

#include "FXGenericPduInstanceType.h"
#include "FXCommonLayoutDetails.h"

class QDomElement;

namespace ASAM {
namespace FIBEX {

class FXFibex;

/**
 * @brief complexType PDU-INSTANCE-TYPE
 *
 * Content model for the entity PDU-INSTANCE.
 */
class VECTOR_DBC_EXPORT FXPduInstanceType : public FXGenericPduInstanceType, public QObject
{
public:
    FXFibex *m_fibex = nullptr;

public:
    FXPduInstanceType(FXFibex *fibex, QObject *parent = Q_NULLPTR);

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /** @must group COMMON-LAYOUT-DETAILS */
    FXCommonLayoutDetails m_commLayoutDetails;
    /** element PDU-UPDATE-BIT-POSITION */
    quint32 *m_pduUpdateBitPosition = nullptr;
};

} // FIBEX
} // ASAM

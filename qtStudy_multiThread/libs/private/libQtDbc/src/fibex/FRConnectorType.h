#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

#include "FXConnectorType.h"

namespace ASAM {
namespace FIBEX {

class FXFibex;

/**
 * @brief complexType CONNECTOR-TYPE
 */
class VECTOR_DBC_EXPORT FRConnectorType : public FXConnectorType , public QObject
{
public:
    FXFibex *m_fibex = nullptr;

public:
    FRConnectorType(FXFibex *fibex, QObject *parent = nullptr);

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /** element WAKE-UP-CHANNEL */
    bool m_wakeUpChannel;
};

} // FIBEX
} // ASAM

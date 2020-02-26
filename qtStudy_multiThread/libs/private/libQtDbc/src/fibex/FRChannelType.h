#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

#include "FXChannelType.h"

namespace ASAM {
namespace FIBEX {

/**
 * @brief complexType CHANNEL-TYPE
 */
class VECTOR_DBC_EXPORT FRChannelType : public FXChannelType, public QObject
{
public:
    FRChannelType(FXFibex *fibex, QObject *parent = nullptr);

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /**
     * @brief FLEXRAY-CHANNEL-NAME
     *
     * Name of the channel.
     */
    QString m_flexrayChannelName;
};

} // FIBEX
} // ASAM

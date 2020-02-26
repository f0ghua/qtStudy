#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

#include "FXAbsolutelyScheduledTimingType.h"
#include "FXRelativelyScheduledTimingType.h"

namespace ASAM {
namespace FIBEX {

class FXFibex;

/**
 * @brief complexType FRAME-TIMINGS
 *
 * Time behavior of a frame specified in a sequence of cluster specific timing types
 */
class VECTOR_DBC_EXPORT FXFrameTimings : public QObject
{
public:
    FXFibex *m_fibex = nullptr;

public:
    FXFrameTimings(FXFibex *fibex, QObject *parent = nullptr);

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /** @opt element RELATIVELY-SCHEDULED-TIMING */
    QList<FXRelativelyScheduledTimingType*> m_relativelyScheduledTimings;
    /** @opt element ABSOLUTELY-SCHEDULED-TIMING */
    QList<FXAbsolutelyScheduledTimingType*> m_absolutelyScheduledTimings;
};

} // FIBEX
} // ASAM

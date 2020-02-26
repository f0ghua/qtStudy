#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

#include "FibexTypes.h"

class QDomElement;

namespace ASAM {
namespace FIBEX {

class FXFibex;

/**
 * @brief complexType RELATIVELY-SCHEDULED-TIMING-TYPE
 *
 * Content model for the entity TIMING in the relatively scheduled peculiarity.
 */
class VECTOR_DBC_EXPORT FXRelativelyScheduledTimingType : public QObject
{
public:
    FXFibex *m_fibex = nullptr;

public:
    FXRelativelyScheduledTimingType(FXFibex *fibex, QObject *parent = nullptr);

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /** @todo DESC */
    QString m_desc;
    /** @todo SCHEDULE-TABLE-NAME */
    QString m_scheduleTableName;
    /** @todo POSITION-IN-TABLE */
    qint16 m_positionInTable;
    /** @todo DELAY */
    XSDuration m_delay;
    /** @todo MANUFACTURER-EXTENSION */
};

} // FIBEX
} // ASAM

#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

#include "FXRevisedElementType.h"
#include "FXSignalTypeType.h"

namespace ASAM {
namespace FIBEX {

class FXFibex;

/**
 * @brief complexType SIGNAL-TYPE
 *
 * Content model for the entity SIGNAL.
 */
class VECTOR_DBC_EXPORT FXSignalType : public FXRevisedElementType, public QObject
{
public:
    FXFibex *m_fibex = nullptr;

public:
    FXSignalType(FXFibex *fibex, QObject *parent = nullptr);

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /**
     * @brief element DEFAULT-VALUE
     *
     * A signals encoded value (internal) indicating that the actual value is currently not published / not of interest
     */
    double m_defaultValue;

    /**
     * @brief element CODING-REF
     *
     * Category of the signal
     */
    QString m_codingRef;

    FXSignalTypeType m_sigType;

    /**
     * @brief element PRIORITY
     *
     * A positive integer indicating the signals priority. 1 means highest priority.
     */
    quint32 m_priority;
};

} // FIBEX
} // ASAM


#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

#include "HOUnitSpec.h"
#include "FXCodings.h"

namespace ASAM {
namespace FIBEX {

class FXFibex;

/**
 * @brief complexType PROCESSING-INFORMATION
 *
 * Data needed to process data in elements.
 */
class VECTOR_DBC_EXPORT FXProcessingInformation : public QObject
{
public:
    FXFibex *m_fibex = nullptr;

public:
    FXProcessingInformation(FXFibex *fibex, QObject *parent = Q_NULLPTR);

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /** element UNIT-SPEC */
    HOUnitSpec *m_unitSpec = nullptr;
    /** element CODINGS */
    FXCodings *m_codings = nullptr;
};

} // FIBEX
} // ASAM

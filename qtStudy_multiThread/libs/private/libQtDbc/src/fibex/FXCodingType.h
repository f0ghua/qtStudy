#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

#include "FXRevisedElementType.h"
#include "HOCodedType.h"
#include "HOCompuMethods.h"

#include <QDebug>

namespace ASAM {
namespace FIBEX {

class FXFibex;

/**
 * @brief complexType CODING-TYPE
 *
 * Content model for the entity CODING.
 */
class VECTOR_DBC_EXPORT CodingType : public FXRevisedElementType, public QObject
{
public:
    FXFibex *m_fibex = nullptr;

public:
    CodingType(FXFibex *fibex, QObject *parent = Q_NULLPTR);

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /** @todo element PHYSICAL-TYPE */
    /** @opt element CODED-TYPE */
    HOCodedType *m_codedType = nullptr;
    /** @opt element COMPU-METHODS */
    HOCompuMethods *m_compuMethods = nullptr;
    /** @todo element MANUFACTURER-EXTENSION */
};

} // FIBEX
} // ASAM

#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

#include "HOCompuMethod.h"

class QDomElement;

namespace ASAM {
namespace FIBEX {

class FXFibex;

/**
 * @brief complexType COMPU-METHODS
 *
 * Container for COMPU-METHOD elements
 */
class VECTOR_DBC_EXPORT HOCompuMethods : public QObject
{
public:
    FXFibex *m_fibex = nullptr;

public:
    HOCompuMethods(FXFibex *fibex, QObject *parent = Q_NULLPTR);

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /** element ho:COMPU-METHOD */
    QList<HOCompuMethod *> m_compuMethods;
};

} // FIBEX
} // ASAM

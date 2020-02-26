#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

#include "FXPduInstanceType.h"

class QDomElement;

namespace ASAM {
namespace FIBEX {

class FXFibex;

/**
 * @brief complexType PDU-INSTANCES
 *
 * A frames layout as a sequence of PDUs
 */
class VECTOR_DBC_EXPORT FXPduInstances : public QObject
{
public:
    FXFibex *m_fibex = nullptr;

public:
    FXPduInstances(FXFibex *fibex, QObject *parent = Q_NULLPTR);

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /** element PDU-INSTANCE */
    QHash<QString, FXPduInstanceType*> m_pduInstances;

};

} // FIBEX
} // ASAM

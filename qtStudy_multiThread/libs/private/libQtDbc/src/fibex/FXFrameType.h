#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

#include "FXRevisedElementType.h"
#include "FXPduInstances.h"

class QDomElement;

namespace ASAM {
namespace FIBEX {

class FXFibex;

/**
 * @brief complexType FRAME-TYPE
 *
 * Content model for the entity FRAME.
 */
class VECTOR_DBC_EXPORT FXFrameTypeCt : public FXRevisedElementType, public QObject
{
public:
    FXFibex *m_fibex = nullptr;

public:
    FXFrameTypeCt(FXFibex *fibex, QObject *parent = nullptr);

    /** load from XML DOM element */
    void load(const QDomElement &element);

    quint32 m_byteLength;
    FibexTypes::FXFrameTypeSt m_frameType;
    FXPduInstances m_pduInstances;
    /** @todo BYTE-LENGTH */
    /** @todo FRAME-TYPE */
    /** @todo PDU-INSTANCES */
    /** @todo MANUFACTURER-EXTENSION */
};

}
}


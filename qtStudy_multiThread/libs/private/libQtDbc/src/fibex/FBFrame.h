#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

#include "FibexTypes.h"

namespace ASAM {
namespace FIBEX {

class FXFrameTypeCt;
class FBPdu;

class VECTOR_DBC_EXPORT FBFrame
{
public:
    FBFrame();
    ~FBFrame();

    QString name() const;
    quint32 byteLength() const;
    FibexTypes::FXFrameTypeSt frameType() const;

    const FXFrameTypeCt *m_fxFrame = nullptr;
    qint32 m_slotId;
    qint16 m_cycleCounter;
    qint16 m_cycleRepetition;
    qint16 m_baseCycle;

    QHash<QString, FBPdu*> m_pdus;
};

} // FIBEX
} // ASAM

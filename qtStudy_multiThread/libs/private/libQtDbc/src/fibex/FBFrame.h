#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

#include "FibexTypes.h"

namespace ASAM {
namespace FIBEX {

class FBPdu;

class VECTOR_DBC_EXPORT FBFrame : public QObject
{
public:
    FBFrame(QObject *parent);

    QString m_shortName;
    quint32 m_byteLength;
    FibexTypes::FXFrameTypeSt m_type;

    qint32 m_slotId;
    qint16 m_cycleCounter;
    qint16 m_baseCycle;
    qint16 m_cycleRepetition;

    QHash<QString, FBPdu*> m_pdus;
};

} // FIBEX
} // ASAM

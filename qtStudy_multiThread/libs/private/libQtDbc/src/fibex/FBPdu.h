#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

#include "FibexTypes.h"

namespace ASAM {
namespace FIBEX {

class FBSignal;

class VECTOR_DBC_EXPORT FBPdu
{
public:
    FBPdu();
    ~FBPdu();

    QString m_shortName;
    quint32 m_byteLength;
    FibexTypes::FXPduTypeSt m_type;

    quint16 m_startBit;
    bool m_isBigEndian;

    QHash<QString, FBSignal*> m_signals;
};

} // FIBEX
} // ASAM

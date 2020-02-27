#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

#include "FibexTypes.h"
#include "FibexKey.h"

namespace ASAM {
namespace FIBEX {

class FBFrame;
class FBPdu;
class FBEcu;
class FRChannelType;

class VECTOR_DBC_EXPORT FBFrameTriggering
{
public:
    FBFrameTriggering() {}
    ~FBFrameTriggering() {m_frames.clear();}

    QHash<QString, FBFrame*> m_frames;
};

class VECTOR_DBC_EXPORT FBPduTriggering
{
public:
    FBPduTriggering() {}
    ~FBPduTriggering() {m_pdus.clear();}

    QHash<QString, FBPdu*> m_pdus;
};

class VECTOR_DBC_EXPORT FBChannel
{
public:
    FBChannel();
    ~FBChannel();

    QString name() const;

    const FRChannelType *m_frChannel = nullptr;
    QHash<QString, FBEcu*> m_ecus;
    QHash<FibexFrameKey, FBFrame*> m_frames;
    QHash<QString, FBFrameTriggering*> m_frameTriggerings;
    QHash<QString, FBPduTriggering*> m_pduTriggerings;
};

} // FIBEX
} // ASAM

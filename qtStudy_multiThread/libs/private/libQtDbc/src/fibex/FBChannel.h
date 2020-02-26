#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

#include "FibexTypes.h"

namespace ASAM {
namespace FIBEX {

class FBFrame;
class FBPdu;

class VECTOR_DBC_EXPORT FBFrameTriggering : public QObject
{
public:
    FBFrameTriggering(QObject *parent) : QObject(parent) {}

    QHash<QString, FBFrame*> m_frames;
};

class VECTOR_DBC_EXPORT FBPduTriggering : public QObject
{
public:
    FBPduTriggering(QObject *parent) : QObject(parent) {}

    QHash<QString, FBPdu*> m_pdus;
};

class VECTOR_DBC_EXPORT FBChannel : public QObject
{
public:
    FBChannel(QObject *parent);

    QHash<QString, FBFrameTriggering*> m_frameTriggerings;
    QHash<QString, FBPduTriggering*> m_pduTriggerings;
};

} // FIBEX
} // ASAM

#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

#include "FibexTypes.h"

namespace ASAM {
namespace FIBEX {

class FBPdu;
class FBFrame;

class VECTOR_DBC_EXPORT FBEcu : public QObject
{
public:
    FBEcu(QObject *parent);

    QHash<QString, FBFrame*> m_inputFrames;
    QHash<QString, FBFrame*> m_outputFrames;
    QHash<QString, FBPdu*> m_inputPdus;
    QHash<QString, FBPdu*> m_outputPdus;
};

} // FIBEX
} // ASAM

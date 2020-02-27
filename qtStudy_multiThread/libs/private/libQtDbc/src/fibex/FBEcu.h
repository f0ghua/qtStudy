#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

#include "FibexTypes.h"

namespace ASAM {
namespace FIBEX {

class FBPdu;
class FBFrame;
class FXEcuType;

class VECTOR_DBC_EXPORT FBEcu
{
public:
    FBEcu();
    ~FBEcu();

    QString name() const;

    const FXEcuType *m_fxEcu = nullptr;

    QHash<QString, FBFrame*> m_inputFrames;
    QHash<QString, FBFrame*> m_outputFrames;
    QHash<QString, FBPdu*> m_inputPdus;
};

} // FIBEX
} // ASAM

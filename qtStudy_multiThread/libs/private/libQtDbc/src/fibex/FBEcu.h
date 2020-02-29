#pragma once

#include "platform.h"
#include "vector_dbc_export.h"
#include "FibexTypes.h"

#include <QDebug>

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

QDebug inline operator<<(QDebug d, const FBEcu &o)
{
    QDebugStateSaver saver(d);
    d.nospace().noquote() << "FBEcu: ("
      << "name:"        << o.name() << ","
      << "ifrmCount:"   << o.m_inputFrames.count() << ","
      << "ofrmCount:"   << (int)o.m_outputFrames.count() << ","
      << "iPduCount:"   << o.m_inputPdus.count()
      << ")";

    return d;
}

} // FIBEX
} // ASAM

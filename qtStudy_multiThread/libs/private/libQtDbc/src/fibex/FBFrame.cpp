#include "FBFrame.h"
#include "Utility.h"
using Vector::DBC::Utility;

namespace ASAM {
namespace FIBEX {

FBFrame::FBFrame(QObject *parent)
    : QObject(parent)
    , m_shortName()
    , m_byteLength(0)
    , m_type(FibexTypes::FXFrameTypeSt::APPLICATION)
    , m_slotId(0)
    , m_cycleCounter(0)
    , m_baseCycle(0)
    , m_cycleRepetition(0)
{
    /* nothing to do here */
}

} // FIBEX
} // ASAM

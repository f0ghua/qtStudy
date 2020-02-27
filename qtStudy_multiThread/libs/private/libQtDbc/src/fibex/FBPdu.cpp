#include "FBPdu.h"
#include "FBPdu.h"
#include "Utility.h"
using Vector::DBC::Utility;

namespace ASAM {
namespace FIBEX {

FBPdu::FBPdu()
    : m_shortName()
    , m_byteLength(0)
    , m_type(FibexTypes::FXPduTypeSt::APPLICATION)
{
    /* nothing to do here */
}

FBPdu::~FBPdu()
{
    m_signals.clear();
}

} // FIBEX
} // ASAM

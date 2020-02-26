#include "FBPdu.h"
#include "FBPdu.h"
#include "Utility.h"
using Vector::DBC::Utility;

namespace ASAM {
namespace FIBEX {

FBPdu::FBPdu(QObject *parent)
    : QObject(parent)
    , m_shortName()
    , m_byteLength(0)
    , m_type(FibexTypes::FXPduTypeSt::APPLICATION)
{
    /* nothing to do here */
}

} // FIBEX
} // ASAM

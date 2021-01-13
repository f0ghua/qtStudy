
#include "CDDDbCVALUETYPE.h"

#include <QDomElement>

namespace vector {
namespace cdd {

CDDDbCVALUETYPE::CDDDbCVALUETYPE()
{
}

CDDDbCVALUETYPE::~CDDDbCVALUETYPE()
{
}

void CDDDbCVALUETYPE::load(const QDomElement &element)
{
    m_bl = element.attribute("bl");
    m_bo = element.attribute("bo");
    m_df = element.attribute("df");
    m_enc = element.attribute("enc");
    m_maxsz = element.attribute("maxsz");
    m_minsz = element.attribute("minsz");
    m_qty = element.attribute("qty");
    m_sig = element.attribute("sig");
    m_sz = element.attribute("sz");

}

} // namespace cdd
} // namespace vector

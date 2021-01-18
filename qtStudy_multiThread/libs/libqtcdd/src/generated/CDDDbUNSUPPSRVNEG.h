#ifndef VECTOR_CDD_CDDDBUNSUPPSRVNEG_H
#define VECTOR_CDD_CDDDBUNSUPPSRVNEG_H

#include "CDDDbUNSUPPSRVNEGImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element UNSUPPSRVNEG
 *
 */
class VECTOR_CDD_API CDDDbUNSUPPSRVNEG : public CDDDbUNSUPPSRVNEGImpl
{
public:
    CDDDbUNSUPPSRVNEG();
    ~CDDDbUNSUPPSRVNEG();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBUNSUPPSRVNEG_H

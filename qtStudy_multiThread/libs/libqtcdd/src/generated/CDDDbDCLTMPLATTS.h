#ifndef VECTOR_CDD_CDDDBDCLTMPLATTS_H
#define VECTOR_CDD_CDDDBDCLTMPLATTS_H

#include "CDDDbDCLTMPLATTSImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element DCLTMPLATTS
 *
 */
class VECTOR_CDD_API CDDDbDCLTMPLATTS : public CDDDbDCLTMPLATTSImpl
{
public:
    CDDDbDCLTMPLATTS();
    ~CDDDbDCLTMPLATTS();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDCLTMPLATTS_H

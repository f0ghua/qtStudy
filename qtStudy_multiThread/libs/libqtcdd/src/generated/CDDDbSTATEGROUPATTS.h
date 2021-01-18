#ifndef VECTOR_CDD_CDDDBSTATEGROUPATTS_H
#define VECTOR_CDD_CDDDBSTATEGROUPATTS_H

#include "CDDDbSTATEGROUPATTSImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element STATEGROUPATTS
 *
 */
class VECTOR_CDD_API CDDDbSTATEGROUPATTS : public CDDDbSTATEGROUPATTSImpl
{
public:
    CDDDbSTATEGROUPATTS();
    ~CDDDbSTATEGROUPATTS();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSTATEGROUPATTS_H

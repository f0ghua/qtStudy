#ifndef VECTOR_CDD_CDDDBPROTOCOLSTANDARD_H
#define VECTOR_CDD_CDDDBPROTOCOLSTANDARD_H

#include "CDDDbPROTOCOLSTANDARDImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element PROTOCOLSTANDARD
 *
 */
class VECTOR_CDD_API CDDDbPROTOCOLSTANDARD : public CDDDbPROTOCOLSTANDARDImpl
{
public:
    CDDDbPROTOCOLSTANDARD();
    ~CDDDbPROTOCOLSTANDARD();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBPROTOCOLSTANDARD_H

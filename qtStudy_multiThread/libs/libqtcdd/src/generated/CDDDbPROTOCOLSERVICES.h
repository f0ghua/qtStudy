#ifndef VECTOR_CDD_CDDDBPROTOCOLSERVICES_H
#define VECTOR_CDD_CDDDBPROTOCOLSERVICES_H

#include "CDDDbPROTOCOLSERVICESImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element PROTOCOLSERVICES
 *
 */
class VECTOR_CDD_API CDDDbPROTOCOLSERVICES : public CDDDbPROTOCOLSERVICESImpl
{
public:
    CDDDbPROTOCOLSERVICES();
    ~CDDDbPROTOCOLSERVICES();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBPROTOCOLSERVICES_H

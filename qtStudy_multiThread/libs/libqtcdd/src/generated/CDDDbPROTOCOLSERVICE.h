#ifndef VECTOR_CDD_CDDDBPROTOCOLSERVICE_H
#define VECTOR_CDD_CDDDBPROTOCOLSERVICE_H

#include "CDDDbPROTOCOLSERVICEImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element PROTOCOLSERVICE
 *
 */
class VECTOR_CDD_API CDDDbPROTOCOLSERVICE : public CDDDbPROTOCOLSERVICEImpl
{
public:
    CDDDbPROTOCOLSERVICE();
    ~CDDDbPROTOCOLSERVICE();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBPROTOCOLSERVICE_H

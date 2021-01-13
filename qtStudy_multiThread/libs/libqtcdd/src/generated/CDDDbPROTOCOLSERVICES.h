#ifndef VECTOR_CDD_CDDDBPROTOCOLSERVICES_H
#define VECTOR_CDD_CDDDBPROTOCOLSERVICES_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbPROTOCOLSERVICE;

/**
 * @brief element PROTOCOLSERVICES
 *
 */
class VECTOR_CDD_API CDDDbPROTOCOLSERVICES
{
public:
    CDDDbPROTOCOLSERVICES();
    ~CDDDbPROTOCOLSERVICES();

    void load(const QDomElement &element);

    /** @element PROTOCOLSERVICE */
    QMap<QString, QSharedPointer<CDDDbPROTOCOLSERVICE>> m_protocolservices;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBPROTOCOLSERVICES_H

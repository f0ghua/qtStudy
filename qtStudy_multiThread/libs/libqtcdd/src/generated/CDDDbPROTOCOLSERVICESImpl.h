#ifndef VECTOR_CDD_CDDDBPROTOCOLSERVICESIMPL_H
#define VECTOR_CDD_CDDDBPROTOCOLSERVICESIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbPROTOCOLSERVICE;

/**
 * @brief element PROTOCOLSERVICES
 *
 */
class VECTOR_CDD_API CDDDbPROTOCOLSERVICESImpl
{
public:
    CDDDbPROTOCOLSERVICESImpl();
    ~CDDDbPROTOCOLSERVICESImpl();

    void load(const QDomElement &element);

    QString m_text;

    /** @element PROTOCOLSERVICE */
    QMap<QString, QSharedPointer<CDDDbPROTOCOLSERVICE>> m_elProtocolservices;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBPROTOCOLSERVICESIMPL_H

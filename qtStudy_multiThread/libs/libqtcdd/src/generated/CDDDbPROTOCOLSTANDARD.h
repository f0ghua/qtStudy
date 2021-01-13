#ifndef VECTOR_CDD_CDDDBPROTOCOLSTANDARD_H
#define VECTOR_CDD_CDDDBPROTOCOLSTANDARD_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {


/**
 * @brief element PROTOCOLSTANDARD
 *
 */
class VECTOR_CDD_API CDDDbPROTOCOLSTANDARD
{
public:
    CDDDbPROTOCOLSTANDARD();
    ~CDDDbPROTOCOLSTANDARD();

    void load(const QDomElement &element);

    QString m_text;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBPROTOCOLSTANDARD_H

#ifndef VECTOR_CDD_CDDDBPROTOCOLSTANDARDIMPL_H
#define VECTOR_CDD_CDDDBPROTOCOLSTANDARDIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {


/**
 * @brief element PROTOCOLSTANDARD
 *
 */
class VECTOR_CDD_API CDDDbPROTOCOLSTANDARDImpl
{
public:
    CDDDbPROTOCOLSTANDARDImpl();
    ~CDDDbPROTOCOLSTANDARDImpl();

    void load(const QDomElement &element);

    QString m_text;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBPROTOCOLSTANDARDIMPL_H

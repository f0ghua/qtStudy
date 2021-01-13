#ifndef VECTOR_CDD_CDDDBDCLSRVTMPLATTS_H
#define VECTOR_CDD_CDDDBDCLSRVTMPLATTS_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbCSTRDEF;
class CDDDbENUMDEF;
class CDDDbSTRDEF;

/**
 * @brief element DCLSRVTMPLATTS
 *
 */
class VECTOR_CDD_API CDDDbDCLSRVTMPLATTS
{
public:
    CDDDbDCLSRVTMPLATTS();
    ~CDDDbDCLSRVTMPLATTS();

    void load(const QDomElement &element);

    /** @element CSTRDEF */
    QSharedPointer<CDDDbCSTRDEF> m_cstrdef;

    /** @element ENUMDEF */
    QSharedPointer<CDDDbENUMDEF> m_enumdef;

    /** @element STRDEF */
    QSharedPointer<CDDDbSTRDEF> m_strdef;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDCLSRVTMPLATTS_H

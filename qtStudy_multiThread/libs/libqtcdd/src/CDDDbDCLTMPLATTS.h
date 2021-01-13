#ifndef VECTOR_CDD_CDDDBDCLTMPLATTS_H
#define VECTOR_CDD_CDDDBDCLTMPLATTS_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbCSTRDEF;
class CDDDbENUMDEF;
class CDDDbSTRDEF;

/**
 * @brief element DCLTMPLATTS
 *
 */
class VECTOR_CDD_API CDDDbDCLTMPLATTS
{
public:
    CDDDbDCLTMPLATTS();
    ~CDDDbDCLTMPLATTS();

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

#endif // VECTOR_CDD_CDDDBDCLTMPLATTS_H

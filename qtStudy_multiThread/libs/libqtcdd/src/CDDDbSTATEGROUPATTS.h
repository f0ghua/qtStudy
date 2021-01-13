#ifndef VECTOR_CDD_CDDDBSTATEGROUPATTS_H
#define VECTOR_CDD_CDDDBSTATEGROUPATTS_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbCSTRDEF;

/**
 * @brief element STATEGROUPATTS
 *
 */
class VECTOR_CDD_API CDDDbSTATEGROUPATTS
{
public:
    CDDDbSTATEGROUPATTS();
    ~CDDDbSTATEGROUPATTS();

    void load(const QDomElement &element);

    /** @element CSTRDEF */
    QSharedPointer<CDDDbCSTRDEF> m_cstrdef;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSTATEGROUPATTS_H

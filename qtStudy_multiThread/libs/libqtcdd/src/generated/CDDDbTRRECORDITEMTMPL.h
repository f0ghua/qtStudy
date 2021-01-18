#ifndef VECTOR_CDD_CDDDBTRRECORDITEMTMPL_H
#define VECTOR_CDD_CDDDBTRRECORDITEMTMPL_H

#include "CDDDbTRRECORDITEMTMPLImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element TRRECORDITEMTMPL
 *
 */
class VECTOR_CDD_API CDDDbTRRECORDITEMTMPL : public CDDDbTRRECORDITEMTMPLImpl
{
public:
    CDDDbTRRECORDITEMTMPL();
    ~CDDDbTRRECORDITEMTMPL();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBTRRECORDITEMTMPL_H

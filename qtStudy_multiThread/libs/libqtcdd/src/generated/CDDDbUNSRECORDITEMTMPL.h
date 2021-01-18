#ifndef VECTOR_CDD_CDDDBUNSRECORDITEMTMPL_H
#define VECTOR_CDD_CDDDBUNSRECORDITEMTMPL_H

#include "CDDDbUNSRECORDITEMTMPLImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element UNSRECORDITEMTMPL
 *
 */
class VECTOR_CDD_API CDDDbUNSRECORDITEMTMPL : public CDDDbUNSRECORDITEMTMPLImpl
{
public:
    CDDDbUNSRECORDITEMTMPL();
    ~CDDDbUNSRECORDITEMTMPL();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBUNSRECORDITEMTMPL_H

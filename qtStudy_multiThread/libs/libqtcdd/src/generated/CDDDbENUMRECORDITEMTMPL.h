#ifndef VECTOR_CDD_CDDDBENUMRECORDITEMTMPL_H
#define VECTOR_CDD_CDDDBENUMRECORDITEMTMPL_H

#include "CDDDbENUMRECORDITEMTMPLImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element ENUMRECORDITEMTMPL
 *
 */
class VECTOR_CDD_API CDDDbENUMRECORDITEMTMPL : public CDDDbENUMRECORDITEMTMPLImpl
{
public:
    CDDDbENUMRECORDITEMTMPL();
    ~CDDDbENUMRECORDITEMTMPL();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBENUMRECORDITEMTMPL_H

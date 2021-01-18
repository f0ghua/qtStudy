#ifndef VECTOR_CDD_CDDDBRECORDTMPL_H
#define VECTOR_CDD_CDDDBRECORDTMPL_H

#include "CDDDbRECORDTMPLImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element RECORDTMPL
 *
 */
class VECTOR_CDD_API CDDDbRECORDTMPL : public CDDDbRECORDTMPLImpl
{
public:
    CDDDbRECORDTMPL();
    ~CDDDbRECORDTMPL();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBRECORDTMPL_H

#ifndef VECTOR_CDD_CDDDBDCLTMPL_H
#define VECTOR_CDD_CDDDBDCLTMPL_H

#include "CDDDbDCLTMPLImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element DCLTMPL
 *
 */
class VECTOR_CDD_API CDDDbDCLTMPL : public CDDDbDCLTMPLImpl
{
public:
    CDDDbDCLTMPL();
    ~CDDDbDCLTMPL();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDCLTMPL_H

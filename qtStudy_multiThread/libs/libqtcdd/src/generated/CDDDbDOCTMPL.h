#ifndef VECTOR_CDD_CDDDBDOCTMPL_H
#define VECTOR_CDD_CDDDBDOCTMPL_H

#include "CDDDbDOCTMPLImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element DOCTMPL
 *
 */
class VECTOR_CDD_API CDDDbDOCTMPL : public CDDDbDOCTMPLImpl
{
public:
    CDDDbDOCTMPL();
    ~CDDDbDOCTMPL();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDOCTMPL_H

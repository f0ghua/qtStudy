#ifndef VECTOR_CDD_CDDDBSTATICCOMPREF_H
#define VECTOR_CDD_CDDDBSTATICCOMPREF_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {


/**
 * @brief element STATICCOMPREF
 *
 */
class VECTOR_CDD_API CDDDbSTATICCOMPREF
{
public:
    CDDDbSTATICCOMPREF();
    ~CDDDbSTATICCOMPREF();

    void load(const QDomElement &element);

    /** @attribute idref */
    QString m_idref;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSTATICCOMPREF_H

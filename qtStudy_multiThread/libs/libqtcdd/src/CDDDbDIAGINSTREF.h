#ifndef VECTOR_CDD_CDDDBDIAGINSTREF_H
#define VECTOR_CDD_CDDDBDIAGINSTREF_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {


/**
 * @brief element DIAGINSTREF
 *
 */
class VECTOR_CDD_API CDDDbDIAGINSTREF
{
public:
    CDDDbDIAGINSTREF();
    ~CDDDbDIAGINSTREF();

    void load(const QDomElement &element);

    /** @attribute idref */
    QString m_idref;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDIAGINSTREF_H

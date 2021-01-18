#ifndef VECTOR_CDD_CDDDBSTATICCOMPREFIMPL_H
#define VECTOR_CDD_CDDDBSTATICCOMPREFIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {


/**
 * @brief element STATICCOMPREF
 *
 */
class VECTOR_CDD_API CDDDbSTATICCOMPREFImpl
{
public:
    CDDDbSTATICCOMPREFImpl();
    ~CDDDbSTATICCOMPREFImpl();

    void load(const QDomElement &element);

    /** @attribute idref */
    QString m_idref;

    QString m_text;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSTATICCOMPREFIMPL_H

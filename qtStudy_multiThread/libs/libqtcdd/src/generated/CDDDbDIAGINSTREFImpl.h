#ifndef VECTOR_CDD_CDDDBDIAGINSTREFIMPL_H
#define VECTOR_CDD_CDDDBDIAGINSTREFIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {


/**
 * @brief element DIAGINSTREF
 *
 */
class VECTOR_CDD_API CDDDbDIAGINSTREFImpl
{
public:
    CDDDbDIAGINSTREFImpl();
    ~CDDDbDIAGINSTREFImpl();

    void load(const QDomElement &element);

    /** @attribute idref */
    QString m_idref;

    QString m_text;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDIAGINSTREFIMPL_H

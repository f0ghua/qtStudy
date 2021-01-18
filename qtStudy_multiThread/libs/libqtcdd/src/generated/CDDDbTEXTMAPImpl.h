#ifndef VECTOR_CDD_CDDDBTEXTMAPIMPL_H
#define VECTOR_CDD_CDDDBTEXTMAPIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbADDINFO;
class CDDDbTEXT;

/**
 * @brief element TEXTMAP
 *
 */
class VECTOR_CDD_API CDDDbTEXTMAPImpl
{
public:
    CDDDbTEXTMAPImpl();
    ~CDDDbTEXTMAPImpl();

    void load(const QDomElement &element);

    /** @attribute e */
    QString m_e;

    /** @attribute s */
    QString m_s;

    QString m_text;

    /** @element ADDINFO */
    QSharedPointer<CDDDbADDINFO> m_elAddinfo;

    /** @element TEXT */
    QSharedPointer<CDDDbTEXT> m_elText;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBTEXTMAPIMPL_H

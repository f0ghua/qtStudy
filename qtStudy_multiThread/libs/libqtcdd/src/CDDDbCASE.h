#ifndef VECTOR_CDD_CDDDBCASE_H
#define VECTOR_CDD_CDDDBCASE_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbSTRUCTURE;

/**
 * @brief element CASE
 *
 */
class VECTOR_CDD_API CDDDbCASE
{
public:
    CDDDbCASE();
    ~CDDDbCASE();

    void load(const QDomElement &element);

    /** @attribute e */
    QString m_e;

    /** @attribute oid */
    QString m_oid;

    /** @attribute s */
    QString m_s;

    /** @attribute temploid */
    QString m_temploid;

    /** @element STRUCTURE */
    QSharedPointer<CDDDbSTRUCTURE> m_structure;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBCASE_H

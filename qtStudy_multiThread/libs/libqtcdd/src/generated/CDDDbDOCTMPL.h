#ifndef VECTOR_CDD_CDDDBDOCTMPL_H
#define VECTOR_CDD_CDDDBDOCTMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbLABEL;
class CDDDbNAME;
class CDDDbQUAL;

/**
 * @brief element DOCTMPL
 *
 */
class VECTOR_CDD_API CDDDbDOCTMPL
{
public:
    CDDDbDOCTMPL();
    ~CDDDbDOCTMPL();

    void load(const QDomElement &element);

    /** @attribute oid */
    QString m_oid;

    /** @attribute saveno */
    QString m_saveno;

    /** @element LABEL */
    QSharedPointer<CDDDbLABEL> m_label;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_name;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_qual;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDOCTMPL_H

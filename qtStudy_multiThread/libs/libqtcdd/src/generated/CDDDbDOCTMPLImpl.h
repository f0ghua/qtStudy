#ifndef VECTOR_CDD_CDDDBDOCTMPLIMPL_H
#define VECTOR_CDD_CDDDBDOCTMPLIMPL_H

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
class VECTOR_CDD_API CDDDbDOCTMPLImpl
{
public:
    CDDDbDOCTMPLImpl();
    ~CDDDbDOCTMPLImpl();

    void load(const QDomElement &element);

    /** @attribute oid */
    QString m_oid;

    /** @attribute saveno */
    QString m_saveno;

    QString m_text;

    /** @element LABEL */
    QSharedPointer<CDDDbLABEL> m_elLabel;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_elName;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_elQual;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDOCTMPLIMPL_H

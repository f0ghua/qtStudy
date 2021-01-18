#ifndef VECTOR_CDD_CDDDBNEGIMPL_H
#define VECTOR_CDD_CDDDBNEGIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbCONSTCOMP;
class CDDDbNAME;
class CDDDbQUAL;
class CDDDbSIMPLEPROXYCOMP;

/**
 * @brief element NEG
 *
 */
class VECTOR_CDD_API CDDDbNEGImpl
{
public:
    CDDDbNEGImpl();
    ~CDDDbNEGImpl();

    void load(const QDomElement &element);

    /** @attribute oid */
    QString m_oid;

    /** @attribute temploid */
    QString m_temploid;

    QString m_text;

    /** @element CONSTCOMP */
    QMap<QString, QSharedPointer<CDDDbCONSTCOMP>> m_elConstcomps;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_elName;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_elQual;

    /** @element SIMPLEPROXYCOMP */
    QMap<QString, QSharedPointer<CDDDbSIMPLEPROXYCOMP>> m_elSimpleproxycomps;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBNEGIMPL_H

#ifndef VECTOR_CDD_CDDDBNEG_H
#define VECTOR_CDD_CDDDBNEG_H

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
class VECTOR_CDD_API CDDDbNEG
{
public:
    CDDDbNEG();
    ~CDDDbNEG();

    void load(const QDomElement &element);

    /** @attribute oid */
    QString m_oid;

    /** @attribute temploid */
    QString m_temploid;

    /** @element CONSTCOMP */
    QSharedPointer<CDDDbCONSTCOMP> m_constcomp;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_name;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_qual;

    /** @element SIMPLEPROXYCOMP */
    QSharedPointer<CDDDbSIMPLEPROXYCOMP> m_simpleproxycomp;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBNEG_H

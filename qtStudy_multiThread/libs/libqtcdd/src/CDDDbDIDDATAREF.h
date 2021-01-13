#ifndef VECTOR_CDD_CDDDBDIDDATAREF_H
#define VECTOR_CDD_CDDDBDIDDATAREF_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbNAME;
class CDDDbQUAL;

/**
 * @brief element DIDDATAREF
 *
 */
class VECTOR_CDD_API CDDDbDIDDATAREF
{
public:
    CDDDbDIDDATAREF();
    ~CDDDbDIDDATAREF();

    void load(const QDomElement &element);

    /** @attribute didRef */
    QString m_didRef;

    /** @attribute oid */
    QString m_oid;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_name;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_qual;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDIDDATAREF_H

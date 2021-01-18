#ifndef VECTOR_CDD_CDDDBDIDDATAREFIMPL_H
#define VECTOR_CDD_CDDDBDIDDATAREFIMPL_H

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
class VECTOR_CDD_API CDDDbDIDDATAREFImpl
{
public:
    CDDDbDIDDATAREFImpl();
    ~CDDDbDIDDATAREFImpl();

    void load(const QDomElement &element);

    /** @attribute didRef */
    QString m_didRef;

    /** @attribute oid */
    QString m_oid;

    QString m_text;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_elName;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_elQual;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDIDDATAREFIMPL_H

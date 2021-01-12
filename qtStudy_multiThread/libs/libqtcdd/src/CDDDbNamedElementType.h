#pragma once

#include "CDDExport.h"
#include "CDDTypes.h"
#include "CDDDbOidElementType.h"

namespace vector {
namespace cdd {

class CDDDbName;
class CDDDbDesc;
class CDDDbQual;

/**
 * @brief element which defined with attribute id
 *
 * id element
 */
class VECTOR_CDD_API CDDDbNamedElementType : public CDDDbOidElementType
{
public:
    CDDDbNamedElementType();
    ~CDDDbNamedElementType();

    /** load from XML DOM element */
    void load(const QDomElement &element);
    QString id() const {return m_id;}
    QString oid() const {return m_oid;}
    QString temploid() const {return m_temploid;}
    QString name() const;
    QString desc() const;
    QString qual() const;

    /** @must attribute oid */
    QString m_oid;

    /** @must attribute temploid */
    QString m_temploid;

    /** element NAME */
    QSharedPointer<CDDDbName> m_name;

    /** element DESC */
    QSharedPointer<CDDDbDesc> m_desc;

    /** element QUAL */
    QSharedPointer<CDDDbQual> m_qual;

};

} // namespace cdd
} // namespace vector

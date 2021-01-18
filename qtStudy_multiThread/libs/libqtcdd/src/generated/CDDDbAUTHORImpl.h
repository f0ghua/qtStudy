#ifndef VECTOR_CDD_CDDDBAUTHORIMPL_H
#define VECTOR_CDD_CDDDBAUTHORIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbCOMPANY;
class CDDDbFIRSTNAME;
class CDDDbLASTNAME;
class CDDDbSHORTNAME;

/**
 * @brief element AUTHOR
 *
 */
class VECTOR_CDD_API CDDDbAUTHORImpl
{
public:
    CDDDbAUTHORImpl();
    ~CDDDbAUTHORImpl();

    void load(const QDomElement &element);

    /** @attribute id */
    QString m_id;

    /** @attribute obs */
    QString m_obs;

    /** @attribute responsible */
    QString m_responsible;

    QString m_text;

    /** @element COMPANY */
    QSharedPointer<CDDDbCOMPANY> m_elCompany;

    /** @element FIRSTNAME */
    QSharedPointer<CDDDbFIRSTNAME> m_elFirstname;

    /** @element LASTNAME */
    QSharedPointer<CDDDbLASTNAME> m_elLastname;

    /** @element SHORTNAME */
    QSharedPointer<CDDDbSHORTNAME> m_elShortname;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBAUTHORIMPL_H

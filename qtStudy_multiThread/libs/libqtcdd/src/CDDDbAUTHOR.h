#ifndef VECTOR_CDD_CDDDBAUTHOR_H
#define VECTOR_CDD_CDDDBAUTHOR_H

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
class VECTOR_CDD_API CDDDbAUTHOR
{
public:
    CDDDbAUTHOR();
    ~CDDDbAUTHOR();

    void load(const QDomElement &element);

    /** @attribute id */
    QString m_id;

    /** @attribute obs */
    QString m_obs;

    /** @attribute responsible */
    QString m_responsible;

    /** @element COMPANY */
    QSharedPointer<CDDDbCOMPANY> m_company;

    /** @element FIRSTNAME */
    QSharedPointer<CDDDbFIRSTNAME> m_firstname;

    /** @element LASTNAME */
    QSharedPointer<CDDDbLASTNAME> m_lastname;

    /** @element SHORTNAME */
    QSharedPointer<CDDDbSHORTNAME> m_shortname;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBAUTHOR_H

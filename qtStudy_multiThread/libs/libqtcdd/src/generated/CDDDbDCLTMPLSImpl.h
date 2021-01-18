#ifndef VECTOR_CDD_CDDDBDCLTMPLSIMPL_H
#define VECTOR_CDD_CDDDBDCLTMPLSIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbDCLTMPL;

/**
 * @brief element DCLTMPLS
 *
 */
class VECTOR_CDD_API CDDDbDCLTMPLSImpl
{
public:
    CDDDbDCLTMPLSImpl();
    ~CDDDbDCLTMPLSImpl();

    void load(const QDomElement &element);

    QString m_text;

    /** @element DCLTMPL */
    QMap<QString, QSharedPointer<CDDDbDCLTMPL>> m_elDcltmpls;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDCLTMPLSIMPL_H

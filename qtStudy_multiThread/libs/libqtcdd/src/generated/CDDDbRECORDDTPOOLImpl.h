#ifndef VECTOR_CDD_CDDDBRECORDDTPOOLIMPL_H
#define VECTOR_CDD_CDDDBRECORDDTPOOLIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbRECORDDT;

/**
 * @brief element RECORDDTPOOL
 *
 */
class VECTOR_CDD_API CDDDbRECORDDTPOOLImpl
{
public:
    CDDDbRECORDDTPOOLImpl();
    ~CDDDbRECORDDTPOOLImpl();

    void load(const QDomElement &element);

    QString m_text;

    /** @element RECORDDT */
    QMap<QString, QSharedPointer<CDDDbRECORDDT>> m_elRecorddts;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBRECORDDTPOOLIMPL_H

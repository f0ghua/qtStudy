#ifndef VECTOR_CDD_CDDDBRECORDTMPLSIMPL_H
#define VECTOR_CDD_CDDDBRECORDTMPLSIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbRECORDTMPL;

/**
 * @brief element RECORDTMPLS
 *
 */
class VECTOR_CDD_API CDDDbRECORDTMPLSImpl
{
public:
    CDDDbRECORDTMPLSImpl();
    ~CDDDbRECORDTMPLSImpl();

    void load(const QDomElement &element);

    QString m_text;

    /** @element RECORDTMPL */
    QVector<QSharedPointer<CDDDbRECORDTMPL>> m_elRecordtmpls;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBRECORDTMPLSIMPL_H

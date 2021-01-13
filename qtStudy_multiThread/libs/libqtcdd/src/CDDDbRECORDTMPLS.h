#ifndef VECTOR_CDD_CDDDBRECORDTMPLS_H
#define VECTOR_CDD_CDDDBRECORDTMPLS_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbRECORDTMPL;

/**
 * @brief element RECORDTMPLS
 *
 */
class VECTOR_CDD_API CDDDbRECORDTMPLS
{
public:
    CDDDbRECORDTMPLS();
    ~CDDDbRECORDTMPLS();

    void load(const QDomElement &element);

    /** @element RECORDTMPL */
    QSharedPointer<CDDDbRECORDTMPL> m_recordtmpl;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBRECORDTMPLS_H

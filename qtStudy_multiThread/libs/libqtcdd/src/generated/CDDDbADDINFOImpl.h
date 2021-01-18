#ifndef VECTOR_CDD_CDDDBADDINFOIMPL_H
#define VECTOR_CDD_CDDDBADDINFOIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbTUV;

/**
 * @brief element ADDINFO
 *
 */
class VECTOR_CDD_API CDDDbADDINFOImpl
{
public:
    CDDDbADDINFOImpl();
    ~CDDDbADDINFOImpl();

    void load(const QDomElement &element);

    QString m_text;

    /** @element TUV */
    QVector<QSharedPointer<CDDDbTUV>> m_elTuvs;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBADDINFOIMPL_H

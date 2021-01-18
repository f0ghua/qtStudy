#ifndef VECTOR_CDD_CDDDBCHOICEIMPL_H
#define VECTOR_CDD_CDDDBCHOICEIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbTUV;

/**
 * @brief element CHOICE
 *
 */
class VECTOR_CDD_API CDDDbCHOICEImpl
{
public:
    CDDDbCHOICEImpl();
    ~CDDDbCHOICEImpl();

    void load(const QDomElement &element);

    QString m_text;

    /** @element TUV */
    QVector<QSharedPointer<CDDDbTUV>> m_elTuvs;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBCHOICEIMPL_H

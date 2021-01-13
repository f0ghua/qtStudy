#ifndef VECTOR_CDD_CDDDBTUV_H
#define VECTOR_CDD_CDDDBTUV_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbPARA;

/**
 * @brief element TUV
 *
 */
class VECTOR_CDD_API CDDDbTUV
{
public:
    CDDDbTUV();
    ~CDDDbTUV();

    void load(const QDomElement &element);

    /** @attribute struct */
    QString m_struct;

    /** @attribute xml:lang */
    QString m_lang;

    QString m_text;

    /** @element PARA */
    QVector<QSharedPointer<CDDDbPARA>> m_paras;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBTUV_H

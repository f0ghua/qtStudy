#ifndef VECTOR_CDD_CDDDBTUVIMPL_H
#define VECTOR_CDD_CDDDBTUVIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbPARA;

/**
 * @brief element TUV
 *
 */
class VECTOR_CDD_API CDDDbTUVImpl
{
public:
    CDDDbTUVImpl();
    ~CDDDbTUVImpl();

    void load(const QDomElement &element);

    /** @attribute struct */
    QString m_struct;

    /** @attribute xml:lang */
    QString m_lang;

    QString m_text;

    /** @element PARA */
    QVector<QSharedPointer<CDDDbPARA>> m_elParas;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBTUVIMPL_H

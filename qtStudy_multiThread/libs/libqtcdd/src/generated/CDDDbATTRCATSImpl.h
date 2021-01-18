#ifndef VECTOR_CDD_CDDDBATTRCATSIMPL_H
#define VECTOR_CDD_CDDDBATTRCATSIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbATTRCAT;

/**
 * @brief element ATTRCATS
 *
 */
class VECTOR_CDD_API CDDDbATTRCATSImpl
{
public:
    CDDDbATTRCATSImpl();
    ~CDDDbATTRCATSImpl();

    void load(const QDomElement &element);

    QString m_text;

    /** @element ATTRCAT */
    QMap<QString, QSharedPointer<CDDDbATTRCAT>> m_elAttrcats;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBATTRCATSIMPL_H

#ifndef VECTOR_CDD_CDDDBATTRCATS_H
#define VECTOR_CDD_CDDDBATTRCATS_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbATTRCAT;

/**
 * @brief element ATTRCATS
 *
 */
class VECTOR_CDD_API CDDDbATTRCATS
{
public:
    CDDDbATTRCATS();
    ~CDDDbATTRCATS();

    void load(const QDomElement &element);

    /** @element ATTRCAT */
    QMap<QString, QSharedPointer<CDDDbATTRCAT>> m_attrcats;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBATTRCATS_H

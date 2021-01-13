#ifndef VECTOR_CDD_CDDDBCHOICE_H
#define VECTOR_CDD_CDDDBCHOICE_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbTUV;

/**
 * @brief element CHOICE
 *
 */
class VECTOR_CDD_API CDDDbCHOICE
{
public:
    CDDDbCHOICE();
    ~CDDDbCHOICE();

    void load(const QDomElement &element);

    /** @element TUV */
    QSharedPointer<CDDDbTUV> m_tuv;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBCHOICE_H

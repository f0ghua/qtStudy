#ifndef VECTOR_CDD_CDDDBLABEL_H
#define VECTOR_CDD_CDDDBLABEL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {


/**
 * @brief element LABEL
 *
 */
class VECTOR_CDD_API CDDDbLABEL
{
public:
    CDDDbLABEL();
    ~CDDDbLABEL();

    void load(const QDomElement &element);

    QString m_text;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBLABEL_H

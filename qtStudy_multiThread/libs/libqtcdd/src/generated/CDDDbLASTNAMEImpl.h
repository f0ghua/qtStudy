#ifndef VECTOR_CDD_CDDDBLASTNAMEIMPL_H
#define VECTOR_CDD_CDDDBLASTNAMEIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {


/**
 * @brief element LASTNAME
 *
 */
class VECTOR_CDD_API CDDDbLASTNAMEImpl
{
public:
    CDDDbLASTNAMEImpl();
    ~CDDDbLASTNAMEImpl();

    void load(const QDomElement &element);

    QString m_text;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBLASTNAMEIMPL_H

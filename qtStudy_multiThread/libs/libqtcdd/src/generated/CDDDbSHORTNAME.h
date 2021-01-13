#ifndef VECTOR_CDD_CDDDBSHORTNAME_H
#define VECTOR_CDD_CDDDBSHORTNAME_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {


/**
 * @brief element SHORTNAME
 *
 */
class VECTOR_CDD_API CDDDbSHORTNAME
{
public:
    CDDDbSHORTNAME();
    ~CDDDbSHORTNAME();

    void load(const QDomElement &element);

    QString m_text;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSHORTNAME_H

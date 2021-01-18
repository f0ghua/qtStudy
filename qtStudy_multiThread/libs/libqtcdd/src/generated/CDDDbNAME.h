#ifndef VECTOR_CDD_CDDDBNAME_H
#define VECTOR_CDD_CDDDBNAME_H

#include "CDDDbNAMEImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element NAME
 *
 */
class VECTOR_CDD_API CDDDbNAME : public CDDDbNAMEImpl
{
public:
    CDDDbNAME();
    ~CDDDbNAME();

    void load(const QDomElement &element);

public:
    QString getValue() const;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBNAME_H

#ifndef VECTOR_CDD_CDDDBCHOICE_H
#define VECTOR_CDD_CDDDBCHOICE_H

#include "CDDDbCHOICEImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element CHOICE
 *
 */
class VECTOR_CDD_API CDDDbCHOICE : public CDDDbCHOICEImpl
{
public:
    CDDDbCHOICE();
    ~CDDDbCHOICE();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBCHOICE_H

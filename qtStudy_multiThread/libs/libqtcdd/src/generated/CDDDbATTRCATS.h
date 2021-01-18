#ifndef VECTOR_CDD_CDDDBATTRCATS_H
#define VECTOR_CDD_CDDDBATTRCATS_H

#include "CDDDbATTRCATSImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element ATTRCATS
 *
 */
class VECTOR_CDD_API CDDDbATTRCATS : public CDDDbATTRCATSImpl
{
public:
    CDDDbATTRCATS();
    ~CDDDbATTRCATS();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBATTRCATS_H

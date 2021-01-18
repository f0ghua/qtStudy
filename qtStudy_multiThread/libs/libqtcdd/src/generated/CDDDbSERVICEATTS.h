#ifndef VECTOR_CDD_CDDDBSERVICEATTS_H
#define VECTOR_CDD_CDDDBSERVICEATTS_H

#include "CDDDbSERVICEATTSImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element SERVICEATTS
 *
 */
class VECTOR_CDD_API CDDDbSERVICEATTS : public CDDDbSERVICEATTSImpl
{
public:
    CDDDbSERVICEATTS();
    ~CDDDbSERVICEATTS();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBSERVICEATTS_H

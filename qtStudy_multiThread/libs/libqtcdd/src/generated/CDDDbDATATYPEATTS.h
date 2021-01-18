#ifndef VECTOR_CDD_CDDDBDATATYPEATTS_H
#define VECTOR_CDD_CDDDBDATATYPEATTS_H

#include "CDDDbDATATYPEATTSImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element DATATYPEATTS
 *
 */
class VECTOR_CDD_API CDDDbDATATYPEATTS : public CDDDbDATATYPEATTSImpl
{
public:
    CDDDbDATATYPEATTS();
    ~CDDDbDATATYPEATTS();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDATATYPEATTS_H

#ifndef VECTOR_CDD_CDDDBDATAOBJATTS_H
#define VECTOR_CDD_CDDDBDATAOBJATTS_H

#include "CDDDbDATAOBJATTSImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element DATAOBJATTS
 *
 */
class VECTOR_CDD_API CDDDbDATAOBJATTS : public CDDDbDATAOBJATTSImpl
{
public:
    CDDDbDATAOBJATTS();
    ~CDDDbDATAOBJATTS();

    void load(const QDomElement &element);

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDATAOBJATTS_H

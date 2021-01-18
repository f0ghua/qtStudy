#include "CDDDbENUMDEF.h"
#include "CDDDbSGNDEF.h"
#include "CDDDbSTRDEF.h"

#include "CDDDbSERVICEATTS.h"

namespace vector {
namespace cdd {

CDDDbSERVICEATTS::CDDDbSERVICEATTS()
{
}

CDDDbSERVICEATTS::~CDDDbSERVICEATTS()
{
}

void CDDDbSERVICEATTS::load(const QDomElement &element)
{
    CDDDbSERVICEATTSImpl::load(element);
}

} // namespace cdd
} // namespace vector

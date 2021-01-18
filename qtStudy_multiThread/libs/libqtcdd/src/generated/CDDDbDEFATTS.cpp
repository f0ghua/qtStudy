#include "CDDDbDATAOBJATTS.h"
#include "CDDDbDATATYPEATTS.h"
#include "CDDDbDCLSRVTMPLATTS.h"
#include "CDDDbDCLTMPLATTS.h"
#include "CDDDbDIAGCLASSATTS.h"
#include "CDDDbDIAGINSTATTS.h"
#include "CDDDbDIDATTS.h"
#include "CDDDbECUATTS.h"
#include "CDDDbJOBATTS.h"
#include "CDDDbJOBCNRATTS.h"
#include "CDDDbRECORDATTS.h"
#include "CDDDbSERVICEATTS.h"
#include "CDDDbSHPROXYATTS.h"
#include "CDDDbSTATEGROUPATTS.h"
#include "CDDDbVARATTS.h"

#include "CDDDbDEFATTS.h"

namespace vector {
namespace cdd {

CDDDbDEFATTS::CDDDbDEFATTS()
{
}

CDDDbDEFATTS::~CDDDbDEFATTS()
{
}

void CDDDbDEFATTS::load(const QDomElement &element)
{
    CDDDbDEFATTSImpl::load(element);
}

} // namespace cdd
} // namespace vector

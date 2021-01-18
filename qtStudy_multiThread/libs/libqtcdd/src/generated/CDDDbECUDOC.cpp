#include "CDDDbATTRCATS.h"
#include "CDDDbAUTHORS.h"
#include "CDDDbDATATYPES.h"
#include "CDDDbDCLTMPLS.h"
#include "CDDDbDEFATTS.h"
#include "CDDDbDESC.h"
#include "CDDDbDIDS.h"
#include "CDDDbDOCTMPL.h"
#include "CDDDbDTCSTATUSMASK.h"
#include "CDDDbDTID.h"
#include "CDDDbECU.h"
#include "CDDDbHISTITEMS.h"
#include "CDDDbNEGRESCODES.h"
#include "CDDDbPROTOCOLSERVICES.h"
#include "CDDDbPROTOCOLSTANDARD.h"
#include "CDDDbQUALGENOPTIONS.h"
#include "CDDDbRECORDDTPOOL.h"
#include "CDDDbRECORDTMPLS.h"
#include "CDDDbSPECOWNER.h"
#include "CDDDbSTATEGROUPS.h"
#include "CDDDbTARGETGROUPS.h"
#include "CDDDbUNSUPPSRVNEG.h"
#include "CDDDbVCKMGR.h"

#include "CDDDbECUDOC.h"

namespace vector {
namespace cdd {

CDDDbECUDOC::CDDDbECUDOC()
{
}

CDDDbECUDOC::~CDDDbECUDOC()
{
}

void CDDDbECUDOC::load(const QDomElement &element)
{
    CDDDbECUDOCImpl::load(element);
}

} // namespace cdd
} // namespace vector

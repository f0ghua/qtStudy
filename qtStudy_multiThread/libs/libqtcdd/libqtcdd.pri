# A. build library
# - Add directory to SUBDIRS
#
# B. use library
# - include <libName>.pri
#

QT += xml

LIB_SRCPATH     = $$PWD
PROJECT_LIBDIR = $$DESTDIR
PROJECT_BINDIR = $$DESTDIR

LIB_NAME = $$qtLibraryTarget(libqtcdd)

!libqtdbc-buildlib{
    LIBS +=  -L$$PROJECT_LIBDIR -l$$LIB_NAME
}else{
    INCLUDEPATH += $$LIB_SRCPATH
    INCLUDEPATH += $$LIB_SRCPATH/inc
    INCLUDEPATH += $$LIB_SRCPATH/src
    DEPENDPATH  += $$LIB_SRCPATH

    win32 {
        QMAKE_CXXFLAGS += -march=i686
    }
    
    !contains(DEFINES, LIB_STATIC) {
        DEFINES += LIB_LIBRARY
        DEFINES += QLIBFIBEX_LIBRARY
    }

    LIB_VERSION_MAJOR   = 1
    LIB_VERSION_MINOR   = 0
    LIB_VERSION_RELEASE = 0
    LIB_VERSION_PATCH   = 0

    LIB_VERSION = '\\"$${LIB_VERSION_MAJOR}.$${LIB_VERSION_MINOR}.$${LIB_VERSION_RELEASE}\\"'
    DEFINES += LIB_VERSION_STR=\"$${LIB_VERSION}\"
    DEFINES += LIB_VERSION_MAJOR=$${LIB_VERSION_MAJOR}
    DEFINES += LIB_VERSION_MINOR=$${LIB_VERSION_MINOR}
    DEFINES += LIB_VERSION_PATCH=$${LIB_VERSION_PATCH}

    SOURCES += \

    HEADERS += \

}

HEADERS += \
    $$PWD/src/CDDDatabase.h \
    $$PWD/src/CDDDbADDINFO.h \
    $$PWD/src/CDDDbATTRCAT.h \
    $$PWD/src/CDDDbATTRCATS.h \
    $$PWD/src/CDDDbAUTHOR.h \
    $$PWD/src/CDDDbAUTHORS.h \
    $$PWD/src/CDDDbCASE.h \
    $$PWD/src/CDDDbCHOICE.h \
    $$PWD/src/CDDDbCOMMONSNAPSHOTDATAPOOL.h \
    $$PWD/src/CDDDbCOMMONSTRING.h \
    $$PWD/src/CDDDbCOMP.h \
    $$PWD/src/CDDDbCOMPANY.h \
    $$PWD/src/CDDDbCONSTCOMP.h \
    $$PWD/src/CDDDbCONTENTCOMP.h \
    $$PWD/src/CDDDbCSTR.h \
    $$PWD/src/CDDDbCSTRDEF.h \
    $$PWD/src/CDDDbCVALUETYPE.h \
    $$PWD/src/CDDDbDATAOBJ.h \
    $$PWD/src/CDDDbDATAOBJATTS.h \
    $$PWD/src/CDDDbDATATYPEATTS.h \
    $$PWD/src/CDDDbDATATYPES.h \
    $$PWD/src/CDDDbDCLSRVTMPL.h \
    $$PWD/src/CDDDbDCLSRVTMPLATTS.h \
    $$PWD/src/CDDDbDCLTMPL.h \
    $$PWD/src/CDDDbDCLTMPLATTS.h \
    $$PWD/src/CDDDbDCLTMPLS.h \
    $$PWD/src/CDDDbDEFATTS.h \
    $$PWD/src/CDDDbDEFAULT.h \
    $$PWD/src/CDDDbDESC.h \
    $$PWD/src/CDDDbDIAGCLASS.h \
    $$PWD/src/CDDDbDIAGCLASSATTS.h \
    $$PWD/src/CDDDbDIAGINST.h \
    $$PWD/src/CDDDbDIAGINSTATTS.h \
    $$PWD/src/CDDDbDIAGINSTREF.h \
    $$PWD/src/CDDDbDID.h \
    $$PWD/src/CDDDbDIDATTS.h \
    $$PWD/src/CDDDbDIDCOMMONSNAPSHOTDATA.h \
    $$PWD/src/CDDDbDIDDATAREF.h \
    $$PWD/src/CDDDbDIDREF.h \
    $$PWD/src/CDDDbDIDREFS.h \
    $$PWD/src/CDDDbDIDS.h \
    $$PWD/src/CDDDbDOCTMPL.h \
    $$PWD/src/CDDDbDOMAINDATAPROXYCOMP.h \
    $$PWD/src/CDDDbDTCSTATUSBITGROUP.h \
    $$PWD/src/CDDDbDTCSTATUSMASK.h \
    $$PWD/src/CDDDbDTID.h \
    $$PWD/src/CDDDbECU.h \
    $$PWD/src/CDDDbECUATTS.h \
    $$PWD/src/CDDDbECUDOC.h \
    $$PWD/src/CDDDbENUM.h \
    $$PWD/src/CDDDbENUMDEF.h \
    $$PWD/src/CDDDbENUMRECORDITEM.h \
    $$PWD/src/CDDDbENUMRECORDITEMTMPL.h \
    $$PWD/src/CDDDbEOSITERCOMP.h \
    $$PWD/src/CDDDbETAG.h \
    $$PWD/src/CDDDbEXCL.h \
    $$PWD/src/CDDDbEXTENDEDDATARECORD.h \
    $$PWD/src/CDDDbEXTENDEDDATARECORDS.h \
    $$PWD/src/CDDDbFAULTMEMORY.h \
    $$PWD/src/CDDDbFC.h \
    $$PWD/src/CDDDbFIRSTNAME.h \
    $$PWD/src/CDDDbGAPDATAOBJ.h \
    $$PWD/src/CDDDbGODTCDATAOBJ.h \
    $$PWD/src/CDDDbGROUPOFDTCPROXYCOMP.h \
    $$PWD/src/CDDDbHISTITEM.h \
    $$PWD/src/CDDDbHISTITEMS.h \
    $$PWD/src/CDDDbIDENT.h \
    $$PWD/src/CDDDbJOBATTS.h \
    $$PWD/src/CDDDbJOBCNR.h \
    $$PWD/src/CDDDbJOBCNRATTS.h \
    $$PWD/src/CDDDbJOBCNRREF.h \
    $$PWD/src/CDDDbLABEL.h \
    $$PWD/src/CDDDbLASTNAME.h \
    $$PWD/src/CDDDbLINCOMP.h \
    $$PWD/src/CDDDbMOD.h \
    $$PWD/src/CDDDbMUXCOMP.h \
    $$PWD/src/CDDDbMUXDT.h \
    $$PWD/src/CDDDbNAME.h \
    $$PWD/src/CDDDbNEG.h \
    $$PWD/src/CDDDbNEGRESCODE.h \
    $$PWD/src/CDDDbNEGRESCODEPROXIES.h \
    $$PWD/src/CDDDbNEGRESCODEPROXY.h \
    $$PWD/src/CDDDbNEGRESCODES.h \
    $$PWD/src/CDDDbNUMITERCOMP.h \
    $$PWD/src/CDDDbPARA.h \
    $$PWD/src/CDDDbPOS.h \
    $$PWD/src/CDDDbPROTOCOLSERVICE.h \
    $$PWD/src/CDDDbPROTOCOLSERVICES.h \
    $$PWD/src/CDDDbPROTOCOLSTANDARD.h \
    $$PWD/src/CDDDbPROXYCOMPREF.h \
    $$PWD/src/CDDDbPVALUETYPE.h \
    $$PWD/src/CDDDbQUAL.h \
    $$PWD/src/CDDDbQUALGENOPTIONS.h \
    $$PWD/src/CDDDbREASON.h \
    $$PWD/src/CDDDbRECORD.h \
    $$PWD/src/CDDDbRECORDATTS.h \
    $$PWD/src/CDDDbRECORDDATAOBJ.h \
    $$PWD/src/CDDDbRECORDDT.h \
    $$PWD/src/CDDDbRECORDDTPOOL.h \
    $$PWD/src/CDDDbRECORDTMPL.h \
    $$PWD/src/CDDDbRECORDTMPLS.h \
    $$PWD/src/CDDDbREQ.h \
    $$PWD/src/CDDDbSERVICE.h \
    $$PWD/src/CDDDbSERVICEATTS.h \
    $$PWD/src/CDDDbSGNDEF.h \
    $$PWD/src/CDDDbSHORTCUTNAME.h \
    $$PWD/src/CDDDbSHORTCUTQUAL.h \
    $$PWD/src/CDDDbSHORTNAME.h \
    $$PWD/src/CDDDbSHPROXY.h \
    $$PWD/src/CDDDbSHPROXYATTS.h \
    $$PWD/src/CDDDbSHSTATIC.h \
    $$PWD/src/CDDDbSIMPLECOMPCONT.h \
    $$PWD/src/CDDDbSIMPLEPROXYCOMP.h \
    $$PWD/src/CDDDbSNAPSHOTRECORDS.h \
    $$PWD/src/CDDDbSPECDATAOBJ.h \
    $$PWD/src/CDDDbSPECIFICSNAPSHOTRECORD.h \
    $$PWD/src/CDDDbSPECOWNER.h \
    $$PWD/src/CDDDbSTATE.h \
    $$PWD/src/CDDDbSTATEGROUP.h \
    $$PWD/src/CDDDbSTATEGROUPATTS.h \
    $$PWD/src/CDDDbSTATEGROUPS.h \
    $$PWD/src/CDDDbSTATICCOMP.h \
    $$PWD/src/CDDDbSTATICCOMPREF.h \
    $$PWD/src/CDDDbSTATICVALUE.h \
    $$PWD/src/CDDDbSTATUSDTCPROXYCOMP.h \
    $$PWD/src/CDDDbSTRDEF.h \
    $$PWD/src/CDDDbSTRING.h \
    $$PWD/src/CDDDbSTRUCT.h \
    $$PWD/src/CDDDbSTRUCTDT.h \
    $$PWD/src/CDDDbSTRUCTURE.h \
    $$PWD/src/CDDDbTARGETGROUP.h \
    $$PWD/src/CDDDbTARGETGROUPS.h \
    $$PWD/src/CDDDbTEXT.h \
    $$PWD/src/CDDDbTEXTMAP.h \
    $$PWD/src/CDDDbTEXTTBL.h \
    $$PWD/src/CDDDbTRRECORDITEM.h \
    $$PWD/src/CDDDbTRRECORDITEMTMPL.h \
    $$PWD/src/CDDDbTUV.h \
    $$PWD/src/CDDDbUNIT.h \
    $$PWD/src/CDDDbUNS.h \
    $$PWD/src/CDDDbUNSDEF.h \
    $$PWD/src/CDDDbUNSRECORDITEM.h \
    $$PWD/src/CDDDbUNSRECORDITEMTMPL.h \
    $$PWD/src/CDDDbUNSUPPSRVNEG.h \
    $$PWD/src/CDDDbVAR.h \
    $$PWD/src/CDDDbVARATTS.h \
    $$PWD/src/CDDDbVCKMGR.h \
    $$PWD/src/CDDExport.h \
    $$PWD/src/CDDFile.h \
    $$PWD/src/CDDLog.h \
    $$PWD/src/CDDTypes.h


SOURCES += \
    $$PWD/src/CDDDatabase.cpp \
    $$PWD/src/CDDDbADDINFO.cpp \
    $$PWD/src/CDDDbATTRCAT.cpp \
    $$PWD/src/CDDDbATTRCATS.cpp \
    $$PWD/src/CDDDbAUTHOR.cpp \
    $$PWD/src/CDDDbAUTHORS.cpp \
    $$PWD/src/CDDDbCASE.cpp \
    $$PWD/src/CDDDbCHOICE.cpp \
    $$PWD/src/CDDDbCOMMONSNAPSHOTDATAPOOL.cpp \
    $$PWD/src/CDDDbCOMMONSTRING.cpp \
    $$PWD/src/CDDDbCOMP.cpp \
    $$PWD/src/CDDDbCOMPANY.cpp \
    $$PWD/src/CDDDbCONSTCOMP.cpp \
    $$PWD/src/CDDDbCONTENTCOMP.cpp \
    $$PWD/src/CDDDbCSTR.cpp \
    $$PWD/src/CDDDbCSTRDEF.cpp \
    $$PWD/src/CDDDbCVALUETYPE.cpp \
    $$PWD/src/CDDDbDATAOBJ.cpp \
    $$PWD/src/CDDDbDATAOBJATTS.cpp \
    $$PWD/src/CDDDbDATATYPEATTS.cpp \
    $$PWD/src/CDDDbDATATYPES.cpp \
    $$PWD/src/CDDDbDCLSRVTMPL.cpp \
    $$PWD/src/CDDDbDCLSRVTMPLATTS.cpp \
    $$PWD/src/CDDDbDCLTMPL.cpp \
    $$PWD/src/CDDDbDCLTMPLATTS.cpp \
    $$PWD/src/CDDDbDCLTMPLS.cpp \
    $$PWD/src/CDDDbDEFATTS.cpp \
    $$PWD/src/CDDDbDEFAULT.cpp \
    $$PWD/src/CDDDbDESC.cpp \
    $$PWD/src/CDDDbDIAGCLASS.cpp \
    $$PWD/src/CDDDbDIAGCLASSATTS.cpp \
    $$PWD/src/CDDDbDIAGINST.cpp \
    $$PWD/src/CDDDbDIAGINSTATTS.cpp \
    $$PWD/src/CDDDbDIAGINSTREF.cpp \
    $$PWD/src/CDDDbDID.cpp \
    $$PWD/src/CDDDbDIDATTS.cpp \
    $$PWD/src/CDDDbDIDCOMMONSNAPSHOTDATA.cpp \
    $$PWD/src/CDDDbDIDDATAREF.cpp \
    $$PWD/src/CDDDbDIDREF.cpp \
    $$PWD/src/CDDDbDIDREFS.cpp \
    $$PWD/src/CDDDbDIDS.cpp \
    $$PWD/src/CDDDbDOCTMPL.cpp \
    $$PWD/src/CDDDbDOMAINDATAPROXYCOMP.cpp \
    $$PWD/src/CDDDbDTCSTATUSBITGROUP.cpp \
    $$PWD/src/CDDDbDTCSTATUSMASK.cpp \
    $$PWD/src/CDDDbDTID.cpp \
    $$PWD/src/CDDDbECU.cpp \
    $$PWD/src/CDDDbECUATTS.cpp \
    $$PWD/src/CDDDbECUDOC.cpp \
    $$PWD/src/CDDDbENUM.cpp \
    $$PWD/src/CDDDbENUMDEF.cpp \
    $$PWD/src/CDDDbENUMRECORDITEM.cpp \
    $$PWD/src/CDDDbENUMRECORDITEMTMPL.cpp \
    $$PWD/src/CDDDbEOSITERCOMP.cpp \
    $$PWD/src/CDDDbETAG.cpp \
    $$PWD/src/CDDDbEXCL.cpp \
    $$PWD/src/CDDDbEXTENDEDDATARECORD.cpp \
    $$PWD/src/CDDDbEXTENDEDDATARECORDS.cpp \
    $$PWD/src/CDDDbFAULTMEMORY.cpp \
    $$PWD/src/CDDDbFC.cpp \
    $$PWD/src/CDDDbFIRSTNAME.cpp \
    $$PWD/src/CDDDbGAPDATAOBJ.cpp \
    $$PWD/src/CDDDbGODTCDATAOBJ.cpp \
    $$PWD/src/CDDDbGROUPOFDTCPROXYCOMP.cpp \
    $$PWD/src/CDDDbHISTITEM.cpp \
    $$PWD/src/CDDDbHISTITEMS.cpp \
    $$PWD/src/CDDDbIDENT.cpp \
    $$PWD/src/CDDDbJOBATTS.cpp \
    $$PWD/src/CDDDbJOBCNR.cpp \
    $$PWD/src/CDDDbJOBCNRATTS.cpp \
    $$PWD/src/CDDDbJOBCNRREF.cpp \
    $$PWD/src/CDDDbLABEL.cpp \
    $$PWD/src/CDDDbLASTNAME.cpp \
    $$PWD/src/CDDDbLINCOMP.cpp \
    $$PWD/src/CDDDbMOD.cpp \
    $$PWD/src/CDDDbMUXCOMP.cpp \
    $$PWD/src/CDDDbMUXDT.cpp \
    $$PWD/src/CDDDbNAME.cpp \
    $$PWD/src/CDDDbNEG.cpp \
    $$PWD/src/CDDDbNEGRESCODE.cpp \
    $$PWD/src/CDDDbNEGRESCODEPROXIES.cpp \
    $$PWD/src/CDDDbNEGRESCODEPROXY.cpp \
    $$PWD/src/CDDDbNEGRESCODES.cpp \
    $$PWD/src/CDDDbNUMITERCOMP.cpp \
    $$PWD/src/CDDDbPARA.cpp \
    $$PWD/src/CDDDbPOS.cpp \
    $$PWD/src/CDDDbPROTOCOLSERVICE.cpp \
    $$PWD/src/CDDDbPROTOCOLSERVICES.cpp \
    $$PWD/src/CDDDbPROTOCOLSTANDARD.cpp \
    $$PWD/src/CDDDbPROXYCOMPREF.cpp \
    $$PWD/src/CDDDbPVALUETYPE.cpp \
    $$PWD/src/CDDDbQUAL.cpp \
    $$PWD/src/CDDDbQUALGENOPTIONS.cpp \
    $$PWD/src/CDDDbREASON.cpp \
    $$PWD/src/CDDDbRECORD.cpp \
    $$PWD/src/CDDDbRECORDATTS.cpp \
    $$PWD/src/CDDDbRECORDDATAOBJ.cpp \
    $$PWD/src/CDDDbRECORDDT.cpp \
    $$PWD/src/CDDDbRECORDDTPOOL.cpp \
    $$PWD/src/CDDDbRECORDTMPL.cpp \
    $$PWD/src/CDDDbRECORDTMPLS.cpp \
    $$PWD/src/CDDDbREQ.cpp \
    $$PWD/src/CDDDbSERVICE.cpp \
    $$PWD/src/CDDDbSERVICEATTS.cpp \
    $$PWD/src/CDDDbSGNDEF.cpp \
    $$PWD/src/CDDDbSHORTCUTNAME.cpp \
    $$PWD/src/CDDDbSHORTCUTQUAL.cpp \
    $$PWD/src/CDDDbSHORTNAME.cpp \
    $$PWD/src/CDDDbSHPROXY.cpp \
    $$PWD/src/CDDDbSHPROXYATTS.cpp \
    $$PWD/src/CDDDbSHSTATIC.cpp \
    $$PWD/src/CDDDbSIMPLECOMPCONT.cpp \
    $$PWD/src/CDDDbSIMPLEPROXYCOMP.cpp \
    $$PWD/src/CDDDbSNAPSHOTRECORDS.cpp \
    $$PWD/src/CDDDbSPECDATAOBJ.cpp \
    $$PWD/src/CDDDbSPECIFICSNAPSHOTRECORD.cpp \
    $$PWD/src/CDDDbSPECOWNER.cpp \
    $$PWD/src/CDDDbSTATE.cpp \
    $$PWD/src/CDDDbSTATEGROUP.cpp \
    $$PWD/src/CDDDbSTATEGROUPATTS.cpp \
    $$PWD/src/CDDDbSTATEGROUPS.cpp \
    $$PWD/src/CDDDbSTATICCOMP.cpp \
    $$PWD/src/CDDDbSTATICCOMPREF.cpp \
    $$PWD/src/CDDDbSTATICVALUE.cpp \
    $$PWD/src/CDDDbSTATUSDTCPROXYCOMP.cpp \
    $$PWD/src/CDDDbSTRDEF.cpp \
    $$PWD/src/CDDDbSTRING.cpp \
    $$PWD/src/CDDDbSTRUCT.cpp \
    $$PWD/src/CDDDbSTRUCTDT.cpp \
    $$PWD/src/CDDDbSTRUCTURE.cpp \
    $$PWD/src/CDDDbTARGETGROUP.cpp \
    $$PWD/src/CDDDbTARGETGROUPS.cpp \
    $$PWD/src/CDDDbTEXT.cpp \
    $$PWD/src/CDDDbTEXTMAP.cpp \
    $$PWD/src/CDDDbTEXTTBL.cpp \
    $$PWD/src/CDDDbTRRECORDITEM.cpp \
    $$PWD/src/CDDDbTRRECORDITEMTMPL.cpp \
    $$PWD/src/CDDDbTUV.cpp \
    $$PWD/src/CDDDbUNIT.cpp \
    $$PWD/src/CDDDbUNS.cpp \
    $$PWD/src/CDDDbUNSDEF.cpp \
    $$PWD/src/CDDDbUNSRECORDITEM.cpp \
    $$PWD/src/CDDDbUNSRECORDITEMTMPL.cpp \
    $$PWD/src/CDDDbUNSUPPSRVNEG.cpp \
    $$PWD/src/CDDDbVAR.cpp \
    $$PWD/src/CDDDbVARATTS.cpp \
    $$PWD/src/CDDDbVCKMGR.cpp \
    $$PWD/src/CDDFile.cpp \
    $$PWD/src/CDDTypes.cpp


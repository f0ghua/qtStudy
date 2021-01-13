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
    $$PWD/src/generated/CDDDbADDINFO.h \
    $$PWD/src/generated/CDDDbATTRCAT.h \
    $$PWD/src/generated/CDDDbATTRCATS.h \
    $$PWD/src/generated/CDDDbAUTHOR.h \
    $$PWD/src/generated/CDDDbAUTHORS.h \
    $$PWD/src/generated/CDDDbCASE.h \
    $$PWD/src/generated/CDDDbCHOICE.h \
    $$PWD/src/generated/CDDDbCOMMONSNAPSHOTDATAPOOL.h \
    $$PWD/src/generated/CDDDbCOMMONSTRING.h \
    $$PWD/src/generated/CDDDbCOMP.h \
    $$PWD/src/generated/CDDDbCOMPANY.h \
    $$PWD/src/generated/CDDDbCONSTCOMP.h \
    $$PWD/src/generated/CDDDbCONTENTCOMP.h \
    $$PWD/src/generated/CDDDbCSTR.h \
    $$PWD/src/generated/CDDDbCSTRDEF.h \
    $$PWD/src/generated/CDDDbCVALUETYPE.h \
    $$PWD/src/generated/CDDDbDATAOBJ.h \
    $$PWD/src/generated/CDDDbDATAOBJATTS.h \
    $$PWD/src/generated/CDDDbDATATYPEATTS.h \
    $$PWD/src/generated/CDDDbDATATYPES.h \
    $$PWD/src/generated/CDDDbDCLSRVTMPL.h \
    $$PWD/src/generated/CDDDbDCLSRVTMPLATTS.h \
    $$PWD/src/generated/CDDDbDCLTMPL.h \
    $$PWD/src/generated/CDDDbDCLTMPLATTS.h \
    $$PWD/src/generated/CDDDbDCLTMPLS.h \
    $$PWD/src/generated/CDDDbDEFATTS.h \
    $$PWD/src/generated/CDDDbDEFAULT.h \
    $$PWD/src/generated/CDDDbDESC.h \
    $$PWD/src/generated/CDDDbDIAGCLASS.h \
    $$PWD/src/generated/CDDDbDIAGCLASSATTS.h \
    $$PWD/src/generated/CDDDbDIAGINST.h \
    $$PWD/src/generated/CDDDbDIAGINSTATTS.h \
    $$PWD/src/generated/CDDDbDIAGINSTREF.h \
    $$PWD/src/generated/CDDDbDID.h \
    $$PWD/src/generated/CDDDbDIDATTS.h \
    $$PWD/src/generated/CDDDbDIDCOMMONSNAPSHOTDATA.h \
    $$PWD/src/generated/CDDDbDIDDATAREF.h \
    $$PWD/src/generated/CDDDbDIDREF.h \
    $$PWD/src/generated/CDDDbDIDREFS.h \
    $$PWD/src/generated/CDDDbDIDS.h \
    $$PWD/src/generated/CDDDbDOCTMPL.h \
    $$PWD/src/generated/CDDDbDOMAINDATAPROXYCOMP.h \
    $$PWD/src/generated/CDDDbDTCSTATUSBITGROUP.h \
    $$PWD/src/generated/CDDDbDTCSTATUSMASK.h \
    $$PWD/src/generated/CDDDbDTID.h \
    $$PWD/src/generated/CDDDbECU.h \
    $$PWD/src/generated/CDDDbECUATTS.h \
    $$PWD/src/generated/CDDDbECUDOC.h \
    $$PWD/src/generated/CDDDbENUM.h \
    $$PWD/src/generated/CDDDbENUMDEF.h \
    $$PWD/src/generated/CDDDbENUMRECORDITEM.h \
    $$PWD/src/generated/CDDDbENUMRECORDITEMTMPL.h \
    $$PWD/src/generated/CDDDbEOSITERCOMP.h \
    $$PWD/src/generated/CDDDbETAG.h \
    $$PWD/src/generated/CDDDbEXCL.h \
    $$PWD/src/generated/CDDDbEXTENDEDDATARECORD.h \
    $$PWD/src/generated/CDDDbEXTENDEDDATARECORDS.h \
    $$PWD/src/generated/CDDDbFAULTMEMORY.h \
    $$PWD/src/generated/CDDDbFC.h \
    $$PWD/src/generated/CDDDbFIRSTNAME.h \
    $$PWD/src/generated/CDDDbGAPDATAOBJ.h \
    $$PWD/src/generated/CDDDbGODTCDATAOBJ.h \
    $$PWD/src/generated/CDDDbGROUPOFDTCPROXYCOMP.h \
    $$PWD/src/generated/CDDDbHISTITEM.h \
    $$PWD/src/generated/CDDDbHISTITEMS.h \
    $$PWD/src/generated/CDDDbIDENT.h \
    $$PWD/src/generated/CDDDbJOBATTS.h \
    $$PWD/src/generated/CDDDbJOBCNR.h \
    $$PWD/src/generated/CDDDbJOBCNRATTS.h \
    $$PWD/src/generated/CDDDbJOBCNRREF.h \
    $$PWD/src/generated/CDDDbLABEL.h \
    $$PWD/src/generated/CDDDbLASTNAME.h \
    $$PWD/src/generated/CDDDbLINCOMP.h \
    $$PWD/src/generated/CDDDbMOD.h \
    $$PWD/src/generated/CDDDbMUXCOMP.h \
    $$PWD/src/generated/CDDDbMUXDT.h \
    $$PWD/src/generated/CDDDbNAME.h \
    $$PWD/src/generated/CDDDbNEG.h \
    $$PWD/src/generated/CDDDbNEGRESCODE.h \
    $$PWD/src/generated/CDDDbNEGRESCODEPROXIES.h \
    $$PWD/src/generated/CDDDbNEGRESCODEPROXY.h \
    $$PWD/src/generated/CDDDbNEGRESCODES.h \
    $$PWD/src/generated/CDDDbNUMITERCOMP.h \
    $$PWD/src/generated/CDDDbPARA.h \
    $$PWD/src/generated/CDDDbPOS.h \
    $$PWD/src/generated/CDDDbPROTOCOLSERVICE.h \
    $$PWD/src/generated/CDDDbPROTOCOLSERVICES.h \
    $$PWD/src/generated/CDDDbPROTOCOLSTANDARD.h \
    $$PWD/src/generated/CDDDbPROXYCOMPREF.h \
    $$PWD/src/generated/CDDDbPVALUETYPE.h \
    $$PWD/src/generated/CDDDbQUAL.h \
    $$PWD/src/generated/CDDDbQUALGENOPTIONS.h \
    $$PWD/src/generated/CDDDbREASON.h \
    $$PWD/src/generated/CDDDbRECORD.h \
    $$PWD/src/generated/CDDDbRECORDATTS.h \
    $$PWD/src/generated/CDDDbRECORDDATAOBJ.h \
    $$PWD/src/generated/CDDDbRECORDDT.h \
    $$PWD/src/generated/CDDDbRECORDDTPOOL.h \
    $$PWD/src/generated/CDDDbRECORDTMPL.h \
    $$PWD/src/generated/CDDDbRECORDTMPLS.h \
    $$PWD/src/generated/CDDDbREQ.h \
    $$PWD/src/generated/CDDDbSERVICE.h \
    $$PWD/src/generated/CDDDbSERVICEATTS.h \
    $$PWD/src/generated/CDDDbSGNDEF.h \
    $$PWD/src/generated/CDDDbSHORTCUTNAME.h \
    $$PWD/src/generated/CDDDbSHORTCUTQUAL.h \
    $$PWD/src/generated/CDDDbSHORTNAME.h \
    $$PWD/src/generated/CDDDbSHPROXY.h \
    $$PWD/src/generated/CDDDbSHPROXYATTS.h \
    $$PWD/src/generated/CDDDbSHSTATIC.h \
    $$PWD/src/generated/CDDDbSIMPLECOMPCONT.h \
    $$PWD/src/generated/CDDDbSIMPLEPROXYCOMP.h \
    $$PWD/src/generated/CDDDbSNAPSHOTRECORDS.h \
    $$PWD/src/generated/CDDDbSPECDATAOBJ.h \
    $$PWD/src/generated/CDDDbSPECIFICSNAPSHOTRECORD.h \
    $$PWD/src/generated/CDDDbSPECOWNER.h \
    $$PWD/src/generated/CDDDbSTATE.h \
    $$PWD/src/generated/CDDDbSTATEGROUP.h \
    $$PWD/src/generated/CDDDbSTATEGROUPATTS.h \
    $$PWD/src/generated/CDDDbSTATEGROUPS.h \
    $$PWD/src/generated/CDDDbSTATICCOMP.h \
    $$PWD/src/generated/CDDDbSTATICCOMPREF.h \
    $$PWD/src/generated/CDDDbSTATICVALUE.h \
    $$PWD/src/generated/CDDDbSTATUSDTCPROXYCOMP.h \
    $$PWD/src/generated/CDDDbSTRDEF.h \
    $$PWD/src/generated/CDDDbSTRING.h \
    $$PWD/src/generated/CDDDbSTRUCT.h \
    $$PWD/src/generated/CDDDbSTRUCTDT.h \
    $$PWD/src/generated/CDDDbSTRUCTURE.h \
    $$PWD/src/generated/CDDDbTARGETGROUP.h \
    $$PWD/src/generated/CDDDbTARGETGROUPS.h \
    $$PWD/src/generated/CDDDbTEXT.h \
    $$PWD/src/generated/CDDDbTEXTMAP.h \
    $$PWD/src/generated/CDDDbTEXTTBL.h \
    $$PWD/src/generated/CDDDbTRRECORDITEM.h \
    $$PWD/src/generated/CDDDbTRRECORDITEMTMPL.h \
    $$PWD/src/generated/CDDDbTUV.h \
    $$PWD/src/generated/CDDDbUNIT.h \
    $$PWD/src/generated/CDDDbUNS.h \
    $$PWD/src/generated/CDDDbUNSDEF.h \
    $$PWD/src/generated/CDDDbUNSRECORDITEM.h \
    $$PWD/src/generated/CDDDbUNSRECORDITEMTMPL.h \
    $$PWD/src/generated/CDDDbUNSUPPSRVNEG.h \
    $$PWD/src/generated/CDDDbVAR.h \
    $$PWD/src/generated/CDDDbVARATTS.h \
    $$PWD/src/generated/CDDDbVCKMGR.h \
    $$PWD/src/CDDExport.h \
    $$PWD/src/CDDFile.h \
    $$PWD/src/CDDLog.h \
    $$PWD/src/CDDTypes.h


SOURCES += \
    $$PWD/src/CDDDatabase.cpp \
    $$PWD/src/generated/CDDDbADDINFO.cpp \
    $$PWD/src/generated/CDDDbATTRCAT.cpp \
    $$PWD/src/generated/CDDDbATTRCATS.cpp \
    $$PWD/src/generated/CDDDbAUTHOR.cpp \
    $$PWD/src/generated/CDDDbAUTHORS.cpp \
    $$PWD/src/generated/CDDDbCASE.cpp \
    $$PWD/src/generated/CDDDbCHOICE.cpp \
    $$PWD/src/generated/CDDDbCOMMONSNAPSHOTDATAPOOL.cpp \
    $$PWD/src/generated/CDDDbCOMMONSTRING.cpp \
    $$PWD/src/generated/CDDDbCOMP.cpp \
    $$PWD/src/generated/CDDDbCOMPANY.cpp \
    $$PWD/src/generated/CDDDbCONSTCOMP.cpp \
    $$PWD/src/generated/CDDDbCONTENTCOMP.cpp \
    $$PWD/src/generated/CDDDbCSTR.cpp \
    $$PWD/src/generated/CDDDbCSTRDEF.cpp \
    $$PWD/src/generated/CDDDbCVALUETYPE.cpp \
    $$PWD/src/generated/CDDDbDATAOBJ.cpp \
    $$PWD/src/generated/CDDDbDATAOBJATTS.cpp \
    $$PWD/src/generated/CDDDbDATATYPEATTS.cpp \
    $$PWD/src/generated/CDDDbDATATYPES.cpp \
    $$PWD/src/generated/CDDDbDCLSRVTMPL.cpp \
    $$PWD/src/generated/CDDDbDCLSRVTMPLATTS.cpp \
    $$PWD/src/generated/CDDDbDCLTMPL.cpp \
    $$PWD/src/generated/CDDDbDCLTMPLATTS.cpp \
    $$PWD/src/generated/CDDDbDCLTMPLS.cpp \
    $$PWD/src/generated/CDDDbDEFATTS.cpp \
    $$PWD/src/generated/CDDDbDEFAULT.cpp \
    $$PWD/src/generated/CDDDbDESC.cpp \
    $$PWD/src/generated/CDDDbDIAGCLASS.cpp \
    $$PWD/src/generated/CDDDbDIAGCLASSATTS.cpp \
    $$PWD/src/generated/CDDDbDIAGINST.cpp \
    $$PWD/src/generated/CDDDbDIAGINSTATTS.cpp \
    $$PWD/src/generated/CDDDbDIAGINSTREF.cpp \
    $$PWD/src/generated/CDDDbDID.cpp \
    $$PWD/src/generated/CDDDbDIDATTS.cpp \
    $$PWD/src/generated/CDDDbDIDCOMMONSNAPSHOTDATA.cpp \
    $$PWD/src/generated/CDDDbDIDDATAREF.cpp \
    $$PWD/src/generated/CDDDbDIDREF.cpp \
    $$PWD/src/generated/CDDDbDIDREFS.cpp \
    $$PWD/src/generated/CDDDbDIDS.cpp \
    $$PWD/src/generated/CDDDbDOCTMPL.cpp \
    $$PWD/src/generated/CDDDbDOMAINDATAPROXYCOMP.cpp \
    $$PWD/src/generated/CDDDbDTCSTATUSBITGROUP.cpp \
    $$PWD/src/generated/CDDDbDTCSTATUSMASK.cpp \
    $$PWD/src/generated/CDDDbDTID.cpp \
    $$PWD/src/generated/CDDDbECU.cpp \
    $$PWD/src/generated/CDDDbECUATTS.cpp \
    $$PWD/src/generated/CDDDbECUDOC.cpp \
    $$PWD/src/generated/CDDDbENUM.cpp \
    $$PWD/src/generated/CDDDbENUMDEF.cpp \
    $$PWD/src/generated/CDDDbENUMRECORDITEM.cpp \
    $$PWD/src/generated/CDDDbENUMRECORDITEMTMPL.cpp \
    $$PWD/src/generated/CDDDbEOSITERCOMP.cpp \
    $$PWD/src/generated/CDDDbETAG.cpp \
    $$PWD/src/generated/CDDDbEXCL.cpp \
    $$PWD/src/generated/CDDDbEXTENDEDDATARECORD.cpp \
    $$PWD/src/generated/CDDDbEXTENDEDDATARECORDS.cpp \
    $$PWD/src/generated/CDDDbFAULTMEMORY.cpp \
    $$PWD/src/generated/CDDDbFC.cpp \
    $$PWD/src/generated/CDDDbFIRSTNAME.cpp \
    $$PWD/src/generated/CDDDbGAPDATAOBJ.cpp \
    $$PWD/src/generated/CDDDbGODTCDATAOBJ.cpp \
    $$PWD/src/generated/CDDDbGROUPOFDTCPROXYCOMP.cpp \
    $$PWD/src/generated/CDDDbHISTITEM.cpp \
    $$PWD/src/generated/CDDDbHISTITEMS.cpp \
    $$PWD/src/generated/CDDDbIDENT.cpp \
    $$PWD/src/generated/CDDDbJOBATTS.cpp \
    $$PWD/src/generated/CDDDbJOBCNR.cpp \
    $$PWD/src/generated/CDDDbJOBCNRATTS.cpp \
    $$PWD/src/generated/CDDDbJOBCNRREF.cpp \
    $$PWD/src/generated/CDDDbLABEL.cpp \
    $$PWD/src/generated/CDDDbLASTNAME.cpp \
    $$PWD/src/generated/CDDDbLINCOMP.cpp \
    $$PWD/src/generated/CDDDbMOD.cpp \
    $$PWD/src/generated/CDDDbMUXCOMP.cpp \
    $$PWD/src/generated/CDDDbMUXDT.cpp \
    $$PWD/src/generated/CDDDbNAME.cpp \
    $$PWD/src/generated/CDDDbNEG.cpp \
    $$PWD/src/generated/CDDDbNEGRESCODE.cpp \
    $$PWD/src/generated/CDDDbNEGRESCODEPROXIES.cpp \
    $$PWD/src/generated/CDDDbNEGRESCODEPROXY.cpp \
    $$PWD/src/generated/CDDDbNEGRESCODES.cpp \
    $$PWD/src/generated/CDDDbNUMITERCOMP.cpp \
    $$PWD/src/generated/CDDDbPARA.cpp \
    $$PWD/src/generated/CDDDbPOS.cpp \
    $$PWD/src/generated/CDDDbPROTOCOLSERVICE.cpp \
    $$PWD/src/generated/CDDDbPROTOCOLSERVICES.cpp \
    $$PWD/src/generated/CDDDbPROTOCOLSTANDARD.cpp \
    $$PWD/src/generated/CDDDbPROXYCOMPREF.cpp \
    $$PWD/src/generated/CDDDbPVALUETYPE.cpp \
    $$PWD/src/generated/CDDDbQUAL.cpp \
    $$PWD/src/generated/CDDDbQUALGENOPTIONS.cpp \
    $$PWD/src/generated/CDDDbREASON.cpp \
    $$PWD/src/generated/CDDDbRECORD.cpp \
    $$PWD/src/generated/CDDDbRECORDATTS.cpp \
    $$PWD/src/generated/CDDDbRECORDDATAOBJ.cpp \
    $$PWD/src/generated/CDDDbRECORDDT.cpp \
    $$PWD/src/generated/CDDDbRECORDDTPOOL.cpp \
    $$PWD/src/generated/CDDDbRECORDTMPL.cpp \
    $$PWD/src/generated/CDDDbRECORDTMPLS.cpp \
    $$PWD/src/generated/CDDDbREQ.cpp \
    $$PWD/src/generated/CDDDbSERVICE.cpp \
    $$PWD/src/generated/CDDDbSERVICEATTS.cpp \
    $$PWD/src/generated/CDDDbSGNDEF.cpp \
    $$PWD/src/generated/CDDDbSHORTCUTNAME.cpp \
    $$PWD/src/generated/CDDDbSHORTCUTQUAL.cpp \
    $$PWD/src/generated/CDDDbSHORTNAME.cpp \
    $$PWD/src/generated/CDDDbSHPROXY.cpp \
    $$PWD/src/generated/CDDDbSHPROXYATTS.cpp \
    $$PWD/src/generated/CDDDbSHSTATIC.cpp \
    $$PWD/src/generated/CDDDbSIMPLECOMPCONT.cpp \
    $$PWD/src/generated/CDDDbSIMPLEPROXYCOMP.cpp \
    $$PWD/src/generated/CDDDbSNAPSHOTRECORDS.cpp \
    $$PWD/src/generated/CDDDbSPECDATAOBJ.cpp \
    $$PWD/src/generated/CDDDbSPECIFICSNAPSHOTRECORD.cpp \
    $$PWD/src/generated/CDDDbSPECOWNER.cpp \
    $$PWD/src/generated/CDDDbSTATE.cpp \
    $$PWD/src/generated/CDDDbSTATEGROUP.cpp \
    $$PWD/src/generated/CDDDbSTATEGROUPATTS.cpp \
    $$PWD/src/generated/CDDDbSTATEGROUPS.cpp \
    $$PWD/src/generated/CDDDbSTATICCOMP.cpp \
    $$PWD/src/generated/CDDDbSTATICCOMPREF.cpp \
    $$PWD/src/generated/CDDDbSTATICVALUE.cpp \
    $$PWD/src/generated/CDDDbSTATUSDTCPROXYCOMP.cpp \
    $$PWD/src/generated/CDDDbSTRDEF.cpp \
    $$PWD/src/generated/CDDDbSTRING.cpp \
    $$PWD/src/generated/CDDDbSTRUCT.cpp \
    $$PWD/src/generated/CDDDbSTRUCTDT.cpp \
    $$PWD/src/generated/CDDDbSTRUCTURE.cpp \
    $$PWD/src/generated/CDDDbTARGETGROUP.cpp \
    $$PWD/src/generated/CDDDbTARGETGROUPS.cpp \
    $$PWD/src/generated/CDDDbTEXT.cpp \
    $$PWD/src/generated/CDDDbTEXTMAP.cpp \
    $$PWD/src/generated/CDDDbTEXTTBL.cpp \
    $$PWD/src/generated/CDDDbTRRECORDITEM.cpp \
    $$PWD/src/generated/CDDDbTRRECORDITEMTMPL.cpp \
    $$PWD/src/generated/CDDDbTUV.cpp \
    $$PWD/src/generated/CDDDbUNIT.cpp \
    $$PWD/src/generated/CDDDbUNS.cpp \
    $$PWD/src/generated/CDDDbUNSDEF.cpp \
    $$PWD/src/generated/CDDDbUNSRECORDITEM.cpp \
    $$PWD/src/generated/CDDDbUNSRECORDITEMTMPL.cpp \
    $$PWD/src/generated/CDDDbUNSUPPSRVNEG.cpp \
    $$PWD/src/generated/CDDDbVAR.cpp \
    $$PWD/src/generated/CDDDbVARATTS.cpp \
    $$PWD/src/generated/CDDDbVCKMGR.cpp \
    $$PWD/src/CDDFile.cpp \
    $$PWD/src/CDDTypes.cpp


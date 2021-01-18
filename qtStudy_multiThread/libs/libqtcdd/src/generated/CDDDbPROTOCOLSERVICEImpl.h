#ifndef VECTOR_CDD_CDDDBPROTOCOLSERVICEIMPL_H
#define VECTOR_CDD_CDDDBPROTOCOLSERVICEIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbDESC;
class CDDDbNAME;
class CDDDbNEG;
class CDDDbNEGRESCODEPROXIES;
class CDDDbPOS;
class CDDDbQUAL;
class CDDDbREQ;

/**
 * @brief element PROTOCOLSERVICE
 *
 */
class VECTOR_CDD_API CDDDbPROTOCOLSERVICEImpl
{
public:
    CDDDbPROTOCOLSERVICEImpl();
    ~CDDDbPROTOCOLSERVICEImpl();

    void load(const QDomElement &element);

    /** @attribute func */
    QString m_func;

    /** @attribute id */
    QString m_id;

    /** @attribute maycombcont */
    QString m_maycombcont;

    /** @attribute mresp */
    QString m_mresp;

    /** @attribute oid */
    QString m_oid;

    /** @attribute periodicresp */
    QString m_periodicresp;

    /** @attribute phys */
    QString m_phys;

    /** @attribute respOnFunc */
    QString m_respOnFunc;

    /** @attribute respOnPhys */
    QString m_respOnPhys;

    /** @attribute sprmibonfunc */
    QString m_sprmibonfunc;

    /** @attribute sprmibonphys */
    QString m_sprmibonphys;

    /** @attribute temploid */
    QString m_temploid;

    QString m_text;

    /** @element DESC */
    QSharedPointer<CDDDbDESC> m_elDesc;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_elName;

    /** @element NEG */
    QSharedPointer<CDDDbNEG> m_elNeg;

    /** @element NEGRESCODEPROXIES */
    QSharedPointer<CDDDbNEGRESCODEPROXIES> m_elNegrescodeproxies;

    /** @element POS */
    QSharedPointer<CDDDbPOS> m_elPos;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_elQual;

    /** @element REQ */
    QSharedPointer<CDDDbREQ> m_elReq;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBPROTOCOLSERVICEIMPL_H

#ifndef VECTOR_CDD_CDDDBPROTOCOLSERVICE_H
#define VECTOR_CDD_CDDDBPROTOCOLSERVICE_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

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
class VECTOR_CDD_API CDDDbPROTOCOLSERVICE
{
public:
    CDDDbPROTOCOLSERVICE();
    ~CDDDbPROTOCOLSERVICE();

    void load(const QDomElement &element);

    /** @attribute func */
    QString m_func;

    /** @attribute id */
    QString m_id;

    /** @attribute mresp */
    QString m_mresp;

    /** @attribute oid */
    QString m_oid;

    /** @attribute phys */
    QString m_phys;

    /** @attribute respOnFunc */
    QString m_respOnFunc;

    /** @attribute respOnPhys */
    QString m_respOnPhys;

    /** @attribute temploid */
    QString m_temploid;

    /** @element NAME */
    QSharedPointer<CDDDbNAME> m_name;

    /** @element NEG */
    QSharedPointer<CDDDbNEG> m_neg;

    /** @element NEGRESCODEPROXIES */
    QSharedPointer<CDDDbNEGRESCODEPROXIES> m_negrescodeproxies;

    /** @element POS */
    QSharedPointer<CDDDbPOS> m_pos;

    /** @element QUAL */
    QSharedPointer<CDDDbQUAL> m_qual;

    /** @element REQ */
    QSharedPointer<CDDDbREQ> m_req;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBPROTOCOLSERVICE_H

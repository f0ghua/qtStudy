#ifndef VECTOR_CDD_CDDDBDATATYPES_H
#define VECTOR_CDD_CDDDBDATATYPES_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbIDENT;
class CDDDbLINCOMP;
class CDDDbMUXDT;
class CDDDbSTRUCTDT;
class CDDDbTEXTTBL;

/**
 * @brief element DATATYPES
 *
 */
class VECTOR_CDD_API CDDDbDATATYPES
{
public:
    CDDDbDATATYPES();
    ~CDDDbDATATYPES();

    void load(const QDomElement &element);

    /** @element IDENT */
    QMap<QString, QSharedPointer<CDDDbIDENT>> m_idents;

    /** @element LINCOMP */
    QMap<QString, QSharedPointer<CDDDbLINCOMP>> m_lincomps;

    /** @element MUXDT */
    QSharedPointer<CDDDbMUXDT> m_muxdt;

    /** @element STRUCTDT */
    QMap<QString, QSharedPointer<CDDDbSTRUCTDT>> m_structdts;

    /** @element TEXTTBL */
    QMap<QString, QSharedPointer<CDDDbTEXTTBL>> m_texttbls;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDATATYPES_H

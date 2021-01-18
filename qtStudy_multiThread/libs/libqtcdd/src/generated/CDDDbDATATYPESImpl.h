#ifndef VECTOR_CDD_CDDDBDATATYPESIMPL_H
#define VECTOR_CDD_CDDDBDATATYPESIMPL_H

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
class VECTOR_CDD_API CDDDbDATATYPESImpl
{
public:
    CDDDbDATATYPESImpl();
    ~CDDDbDATATYPESImpl();

    void load(const QDomElement &element);

    QString m_text;

    /** @element IDENT */
    QMap<QString, QSharedPointer<CDDDbIDENT>> m_elIdents;

    /** @element LINCOMP */
    QMap<QString, QSharedPointer<CDDDbLINCOMP>> m_elLincomps;

    /** @element MUXDT */
    QMap<QString, QSharedPointer<CDDDbMUXDT>> m_elMuxdts;

    /** @element STRUCTDT */
    QMap<QString, QSharedPointer<CDDDbSTRUCTDT>> m_elStructdts;

    /** @element TEXTTBL */
    QMap<QString, QSharedPointer<CDDDbTEXTTBL>> m_elTexttbls;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBDATATYPESIMPL_H

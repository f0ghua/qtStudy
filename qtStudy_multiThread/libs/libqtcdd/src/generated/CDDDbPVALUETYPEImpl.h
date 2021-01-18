#ifndef VECTOR_CDD_CDDDBPVALUETYPEIMPL_H
#define VECTOR_CDD_CDDDBPVALUETYPEIMPL_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbUNIT;

/**
 * @brief element PVALUETYPE
 *
 */
class VECTOR_CDD_API CDDDbPVALUETYPEImpl
{
public:
    CDDDbPVALUETYPEImpl();
    ~CDDDbPVALUETYPEImpl();

    void load(const QDomElement &element);

    /** @attribute bl */
    QString m_bl;

    /** @attribute bo */
    QString m_bo;

    /** @attribute df */
    QString m_df;

    /** @attribute enc */
    QString m_enc;

    /** @attribute maxsz */
    QString m_maxsz;

    /** @attribute minsz */
    QString m_minsz;

    /** @attribute qty */
    QString m_qty;

    /** @attribute sig */
    QString m_sig;

    /** @attribute sz */
    QString m_sz;

    QString m_text;

    /** @element UNIT */
    QSharedPointer<CDDDbUNIT> m_elUnit;

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBPVALUETYPEIMPL_H

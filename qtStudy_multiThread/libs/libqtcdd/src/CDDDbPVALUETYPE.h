#ifndef VECTOR_CDD_CDDDBPVALUETYPE_H
#define VECTOR_CDD_CDDDBPVALUETYPE_H

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {


/**
 * @brief element PVALUETYPE
 *
 */
class VECTOR_CDD_API CDDDbPVALUETYPE
{
public:
    CDDDbPVALUETYPE();
    ~CDDDbPVALUETYPE();

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

};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBPVALUETYPE_H

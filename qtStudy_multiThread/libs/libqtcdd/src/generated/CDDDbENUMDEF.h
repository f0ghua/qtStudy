#ifndef VECTOR_CDD_CDDDBENUMDEF_H
#define VECTOR_CDD_CDDDBENUMDEF_H

#include "CDDDbENUMDEFImpl.h"

namespace vector {
namespace cdd {

/**
 * @brief element ENUMDEF
 *
 */
class VECTOR_CDD_API CDDDbENUMDEF : public CDDDbENUMDEFImpl
{
public:
    CDDDbENUMDEF();
    ~CDDDbENUMDEF();

    void load(const QDomElement &element);

public:
    const QMap<QString, QString> &elETags() const {return m_elEtagsCtr;}
    const QString &v() const {return m_v;}

    /*!
     * \brief m_elEtagsCtr
     * QMap<v, text>
     */
    QMap<QString, QString> m_elEtagsCtr;
};

} // namespace cdd
} // namespace vector

#endif // VECTOR_CDD_CDDDBENUMDEF_H

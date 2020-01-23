#pragma once

#include <QObject>

#include "platform.h"
#include "vector_dbc_export.h"

#include "FXFibex.h"

class QDomElement;

namespace ASAM {
namespace FIBEX {

class VECTOR_DBC_EXPORT Fibex : public FXFibex
{
public:
    Fibex();
    virtual ~Fibex();

    /**
     * @brief Load Database
     * @param[in] filename File Name
     *
     * Loads database.
     */
    bool load(const QDomElement &element);

private:
    QDomElement *m_domElement;
};

}
}

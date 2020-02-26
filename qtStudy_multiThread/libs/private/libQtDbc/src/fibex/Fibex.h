#pragma once

#include <QObject>

#include "platform.h"
#include "vector_dbc_export.h"

#include "FBSignal.h"
#include "FBPdu.h"
#include "FBFrame.h"
#include "FBChannel.h"
#include "FBEcu.h"

#include "FXFibex.h"

class QDomElement;

namespace ASAM {
namespace FIBEX {

class VECTOR_DBC_EXPORT Fibex : public FXFibex
{
public:
    Fibex(QObject *parent = nullptr);
    virtual ~Fibex();

    /**
     * @brief Load Database
     * @param[in] filename File Name
     *
     * Loads database.
     */
    bool load(const QDomElement &element);

public:
    bool covertXml2Db();

    QHash<QString, FBEcu*> m_ecus;
    QHash<QString, FBChannel*> m_channels;
    QHash<QString, FBFrame*> m_frames;
    QHash<QString, FBPdu*> m_pdus;
    QHash<QString, FBSignal*> m_signals;

private:
    QDomElement *m_domElement;

};

}
}

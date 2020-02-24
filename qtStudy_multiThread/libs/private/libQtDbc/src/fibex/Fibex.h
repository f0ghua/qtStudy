#pragma once

#include <QObject>

#include "platform.h"
#include "vector_dbc_export.h"

#include "FBSignal.h"
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

//    QList<FBChannel>  m_channelList;
//    QList<FBEcu> m_ecuList;
//    QList<FBFrame> m_frameList;
//    QList<FBPdu> m_pduList;
    QHash<QString, FBSignal *> m_signals;

private:
    QDomElement *m_domElement;

};

}
}

#pragma once

#include <QObject>

#include "platform.h"
#include "asam_fibex_export.h"

class QDomElement;

namespace ASAM {
namespace FIBEX {

class Fibex;

/**
 * File
 */
class ASAM_FIBEX_EXPORT File
{
public:
    File();
    ~File();
    QString filename() {return m_fileName;}

    bool load(const char *fileName);
    bool load(const QString &fileName);

private:
    Fibex *m_fibex;
    QString m_fileName;

};

} // FIBEX
} // ASAM

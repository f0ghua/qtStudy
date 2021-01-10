#pragma once

#include "CDDExport.h"

#include <QObject>

namespace vector {
namespace cdd {

class CDDDatabase;

class VECTOR_CDD_API CDDFile
{
public:
    CDDFile();
    ~CDDFile();
    QString filename() {return m_fileName;}
    CDDDatabase *db() {return m_db;}

    bool load(const QString &fileName);

private:
    CDDDatabase *m_db;
    QString m_fileName;

};

} // namespace cdd
} // namespace vector


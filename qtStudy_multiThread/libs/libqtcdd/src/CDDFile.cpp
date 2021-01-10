#include "CDDDatabase.h"
#include "CDDFile.h"

#include <QRegularExpression>
#include <QFile>
#include <QFileInfo>
#include <QXmlStreamReader>
#include <QDomDocument>
#include <QDomElement>
#include <QDebug>

//#define F_NO_DEBUG

namespace vector {
namespace cdd {


CDDFile::CDDFile()
{
    m_db = new CDDDatabase();
}

CDDFile::~CDDFile()
{
    delete m_db;
}

bool CDDFile::load(const QString &fileName)
{
    bool ret = true;

    QFileInfo fi = QFileInfo(fileName);
    QString ext = fi.suffix();

    QFile *inFile = new QFile(fileName);

#ifndef F_NO_DEBUG
    qDebug() << "CDDFile: " << fileName;
#endif

    if (!inFile->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        delete inFile;
        return false;
    }

    m_fileName = fileName;
#ifndef F_NO_DEBUG
    qDebug() << "Starting fibex load";
#endif

    QDomDocument doc;
    QString errorStr;
    int errorLine;
    int errorColumn;

    if (!doc.setContent(inFile, false, &errorStr, &errorLine, &errorColumn))
    {
        qDebug() << "Error: Parse error at line " << errorLine << ", "
                  << "column " << errorColumn << ": "
                  << qPrintable(errorStr);
		
        inFile->close();
        delete inFile;
        return false;
    }

    QDomElement root = doc.documentElement();

    qDebug() << root.tagName();

    m_db->load(root);

#ifndef F_NO_DEBUG
    qDebug() << "m_db load finish";
#endif
    inFile->close();
    delete inFile;
#ifndef F_NO_DEBUG
    qDebug() << "inFile closed";
#endif
    return ret;
}

} // namespace cdd
} // namespace vector

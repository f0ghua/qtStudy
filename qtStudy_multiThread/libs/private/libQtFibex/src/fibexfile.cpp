#include "File.h"
#include "DBCHelper.h"

#include "Fibex.h"

#include <QRegularExpression>
#include <QFile>
#include <QFileInfo>
#include <QXmlStreamReader>
#include <QDomDocument>
#include <QDomElement>
#include <QDebug>

//#define F_NO_DEBUG
using namespace ASAM::FIBEX;

namespace Vector {
namespace DBC {

Status File::loadFibexFile(const QString &fileName)
{
    Status ret = Status::Ok;
    QFile *inFile = new QFile(fileName);

#ifndef F_NO_DEBUG
    qDebug() << "Fibex File: " << fileName;
#endif

    if (!inFile->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        delete inFile;
        return Status::FileOpenError;
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
        return Status::Error;
    }

    QDomElement root = doc.documentElement();

    qDebug() << root.tagName();

    //ret = xmlParseFibex(root);
    ASAM::FIBEX::Fibex fb;
    fb.load(root);

    inFile->close();
    delete inFile;

    return ret;
}


}
}

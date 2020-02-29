#include "File.h"
#include "Fibex.h"

#include <QRegularExpression>
#include <QFile>
#include <QFileInfo>
#include <QXmlStreamReader>
#include <QDomDocument>
#include <QDomElement>
#include <QDebug>

#define F_NO_DEBUG

namespace ASAM {
namespace FIBEX {

File::File()
{
    /* nothing to do here */
    //m_pNetHandle = new NetworkHandle();
    //m_pNetwork = m_pNetHandle->getNetwork();
}

File::~File()
{
    /* nothing to do here */
    //delete m_pNetHandle;
}

bool File::load(const QString &fileName)
{
    QFileInfo fi = QFileInfo(fileName);
    QString ext = fi.suffix();

    return loadFibexFile(fileName);
}

bool File::loadFibexFile(const QString &fileName)
{
    bool ret = true;
    QFile *inFile = new QFile(fileName);

#ifndef F_NO_DEBUG
    qDebug() << "Fibex File: " << fileName;
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
        return false;
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

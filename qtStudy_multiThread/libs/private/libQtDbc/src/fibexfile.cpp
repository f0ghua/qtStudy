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

    // convert to network tree
    m_pNetwork->nodes.clear();
    m_pNetwork->removeAllMessages();
    QFileInfo fileinfo = QFileInfo(fileName);
    m_pNetwork->name = fileinfo.baseName();

#if 0
    QXmlStreamReader xml(inFile);
    Node processingEcu;

    while (!xml.atEnd()) {
          xml.readNext();

          if(xml.isStartElement()) {
              //qDebug() << "<" << xml.name();

              if (xml.name() == "ECU") {
                  QString idStr = xml.attributes().value(QString("ID")).toString();
                  qDebug() << "@ECU ID = " << idStr;

                  Node tmpEcu;
                  //tmpEcu.idRef = idStr;
                  processingEcu = tmpEcu;

              }
              if (xml.name() == "SHORT-NAME") {

              }


              if (xml.name() == "FRAME-TRIGGERING") {
                  QString idStr = xml.attributes().value(QString("ID")).toString();
                  qDebug() << "@FRAME-TRIGGERING ID = " << idStr;
              }
              if (xml.name() == "SLOT-ID") {
                  QString text = xml.readElementText();
                  qDebug() << "@SLOT-ID" << text;
              }
          }

          if(xml.isEndElement()) {
              //qDebug() << ">" << xml.name();
              if (xml.name() == "ECU") {
                  m_pNetwork->addNode(processingEcu);
              }
          }
    }

    if (xml.hasError()) {

    }
#endif

    inFile->close();
    delete inFile;

    return ret;
}


}
}

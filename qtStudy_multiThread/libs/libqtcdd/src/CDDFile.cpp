#include "CDDDatabase.h"
#include "CDDFile.h"

#include "CDDDbECUDoc.h"
#include "CDDDbDefAtts.h"
#include "CDDDbECUAtts.h"
#include "CDDDbEnumDef.h"
#include "CDDDbAttrCats.h"
#include "CDDDbAttrCat.h"
#include "CDDDbUnsDef.h"



#include <QRegularExpression>
#include <QFile>
#include <QFileInfo>
#include <QXmlStreamReader>
#include <QDomDocument>
#include <QDomElement>
#include <QDebug>

//#define F_NO_DEBUG

namespace {
using namespace vector::cdd;

void dump(const CDDDatabase &cddDb)
{
    const auto &ecudoc = cddDb.m_ecudoc;
    const auto &attrcats = ecudoc->m_attrcats->m_attrcats;
    const auto &ecuatts = ecudoc->m_defatts->m_ecuatts;

    for (const auto &def : ecuatts->m_enumdefs) {
        QString attrcatRef = def->attrcatref();
        QString category;
        if (attrcats.contains(attrcatRef)) {
            const auto &attrcat = attrcats.value(attrcatRef);
            category = attrcat->name();
        }
        qDebug() << QObject::tr("[category] %1, [enum] %2, [value]%3").arg(category, 16).arg(def->name(), 32).arg(def->value(), 16);
    }

    for (const auto &def : ecuatts->m_unsdefs) {
        QString attrcatRef = def->attrcatref();
        QString category;
        if (attrcats.contains(attrcatRef)) {
            const auto &attrcat = attrcats.value(attrcatRef);
            category = attrcat->name();
        }
        qDebug() << QObject::tr("[category] %1, [uns] %2, [value]%3").arg(category, 16).arg(def->name(), 32).arg(def->value(), 16);
    }
}


}


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
#ifndef F_NO_DEBUG
        qDebug() << "file not found or can't open";
#endif
        delete inFile;
        return false;
    }

    m_fileName = fileName;
#ifndef F_NO_DEBUG
    qDebug() << "Starting cdd load";
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

    dump(*m_db);

    return ret;
}

} // namespace cdd
} // namespace vector

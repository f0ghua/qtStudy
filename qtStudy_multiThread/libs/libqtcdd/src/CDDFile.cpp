#include "CDDDatabase.h"
#include "CDDFile.h"
#include "CDDDbIncludes.h"

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
    const auto &attrcats = ecudoc->m_elAttrcats->m_elAttrcats;
    const auto &ecuatts = ecudoc->m_elDefatts->m_elEcuatts;

    for (const auto &def : ecuatts->m_elEnumdefs) {
        QString attrcatRef = def->m_attrcatref;
        QString category;
        if (attrcats.contains(attrcatRef)) {
            const auto &attrcat = attrcats.value(attrcatRef);
            category = attrcat->m_elName->getValue();
        }
        qDebug() << QObject::tr("[category] %1, [enum] %2, [value]%3").arg(category, 16).arg(def->m_elName->getValue(), 32).arg(def->m_v, 16);
    }

    for (const auto &def : ecuatts->m_elUnsdefs) {
        QString attrcatRef = def->m_attrcatref;
        QString category;
        if (attrcats.contains(attrcatRef)) {
            const auto &attrcat = attrcats.value(attrcatRef);
            category = attrcat->m_elName->getValue();
        }
        qDebug() << QObject::tr("[category] %1, [uns] %2, [value]%3").arg(category, 16).arg(def->m_elName->getValue(), 32).arg(def->m_v, 16);
    }


    const auto &vars = ecudoc->m_elEcu->m_elVars;
    QSharedPointer<CDDDbVAR> var;
    for (auto v : vars) {
        if (v->m_elQual->m_text == "Base_Variant") {
            var = v;
        }
    }
    if (var.isNull()) {
        qDebug() << "Base_Variant is not found";
    }
    const auto &diagclasses = var->m_elDiagclasss;
    for (const auto &dclass : diagclasses) {
        qDebug() << "DIAGCLASS" << dclass->m_elName->getValue();

        const auto diaginsts = dclass->m_elDiaginsts;
        for (const auto &dinst : diaginsts) {
            qDebug() << QString("%1").arg("DIAGINST", 16) << dinst->m_elName->getValue();
        }
    }

}


} // namespace


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

    //dump(*m_db);
    m_db->parse();

    auto rets = m_db->getInterfaceParameters();
    for (auto i : rets) {
        qDebug() << i;
    }

    return ret;
}

} // namespace cdd
} // namespace vector

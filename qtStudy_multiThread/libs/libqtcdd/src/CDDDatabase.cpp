#include "CDDLog.h"
#include "CDDDbECUDOC.h"
#include "CDDDatabase.h"
#include "CDDDbIncludes.h"

#include <QDomElement>

namespace {
using namespace vector::cdd;
using InterfaceParameter = CDDDatabase::InterfaceParameter;

void parseSupportedInterfaces(const QSharedPointer<CDDDbECUDOC> &ecudoc,
                              QMap<QString, bool> &supportedInterfaces)
{
    if (ecudoc.isNull()
            || ecudoc->m_elAttrcats.isNull()
            || ecudoc->m_elDefatts.isNull()) {
        return;
    }

    const auto &attrcats = ecudoc->m_elAttrcats->m_elAttrcats;
    const auto &ecuatts = ecudoc->m_elDefatts->m_elEcuatts;

    for (const auto &def : ecuatts->m_elEnumdefs) {
        if (def.isNull()) continue;

        QString attrcatRef = def->m_attrcatref;
        QString category;
        if (attrcats.contains(attrcatRef)) {
            const auto &attrcat = attrcats.value(attrcatRef);
            category = attrcat->m_elName->getValue();
            if (category == "Available interfaces") {
                const auto &etags = def->elETags();
                bool isSupported = false;
                if (etags.contains(def->v())) {
                    isSupported = (etags.value(def->v()) == "supported");
                }
                supportedInterfaces.insert(def->m_elName->getValue(), isSupported);
            }
        }
    }
}

void parseInterfaceParameters(const QSharedPointer<CDDDbECUDOC> &ecudoc,
                              QMap<QString, InterfaceParameter> &interfaceParameters)
{
    if (ecudoc.isNull()
            || ecudoc->m_elAttrcats.isNull()
            || ecudoc->m_elDefatts.isNull()) {
        return;
    }

    const auto &attrcats = ecudoc->m_elAttrcats->m_elAttrcats;
    const auto &ecuatts = ecudoc->m_elDefatts->m_elEcuatts;

    for (const auto &def : ecuatts->m_elEnumdefs) {
        if (def.isNull()) continue;
        InterfaceParameter pm;

        pm.m_type = CDDAttrType::eENUM;
        pm.m_name = def->m_elName->getValue();

        QString attrcatRef = def->m_attrcatref;
        if (attrcats.contains(attrcatRef)) {
            const auto &attrcat = attrcats.value(attrcatRef);
            pm.m_category = attrcat->m_elName->getValue();
        }

        pm.m_value = def->m_v.toUInt();

        const auto &etags = def->elETags();
        for (auto it = etags.begin(); it != etags.end(); ++it) {
            pm.m_enumTable.insert(it.key().toUInt(), it.value());
        }

        interfaceParameters.insert(pm.m_name, pm);
    }

    for (const auto &def : ecuatts->m_elUnsdefs) {
        if (def.isNull()) continue;
        InterfaceParameter pm;

        pm.m_type = CDDAttrType::eUNSIGNED;
        pm.m_name = def->m_elName->getValue();

        QString attrcatRef = def->m_attrcatref;
        if (attrcats.contains(attrcatRef)) {
            const auto &attrcat = attrcats.value(attrcatRef);
            pm.m_category = attrcat->m_elName->getValue();
        }

        pm.m_value = def->m_v.toUInt();
        pm.m_displayFormat = (def->m_df == "dec")?CDDUnsignedDataFormat::eDEC:CDDUnsignedDataFormat::eHEX;

        interfaceParameters.insert(pm.m_name, pm);
    }
}


} // namespace


namespace vector {
namespace cdd {

CDDDatabase::CDDDatabase()
{
}

CDDDatabase::~CDDDatabase()
{

}

void CDDDatabase::load(const QDomElement &element)
{
    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        const QDomElement &childElement = child.toElement();
#ifndef F_NO_DEBUG
        QLOG_TRACE() << "CDDDatabase::load" << childElement.tagName();
#endif
        if (childElement.tagName() == "ECUDOC") {
            m_ecudoc = QSharedPointer<CDDDbECUDOC>::create();
            m_ecudoc->load(childElement);
        }

        child = child.nextSibling();
    }
}

void CDDDatabase::parse()
{
    parseSupportedInterfaces(m_ecudoc, m_supportedInterfaces);
    parseInterfaceParameters(m_ecudoc, m_interfaceParameters);
}

} // namespace cdd
} // namespace vector

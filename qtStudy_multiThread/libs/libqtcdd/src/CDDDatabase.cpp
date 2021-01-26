#include "CDDLog.h"
#include "CDDDbECUDOC.h"
#include "CDDDatabase.h"
#include "CDDDbIncludes.h"

#include <QDomElement>

namespace {
using namespace vector::cdd;
using InterfaceParameter    = CDDDatabase::InterfaceParameters;
using InterfaceProperties   = CDDDatabase::InterfaceProperties;
using ServiceProperties     = CDDDatabase::ServiceProperties;

static const char QUAL_PREFIX_CAN[] = "CAN.";

template<typename T>
inline QString getCategory(
        const QSharedPointer<T> &def,
        const QMap<QString, QSharedPointer<CDDDbATTRCAT>> &attrcats)
{
    QString attrcatRef = def->m_attrcatref;
    if (attrcats.contains(attrcatRef)) {
        const auto &attrcat = attrcats.value(attrcatRef);
        return attrcat->m_elName->getValue();
    }
    return QString();
};

void parseSupportedInterfaces(const QSharedPointer<CDDDbECUDOC> &ecudoc,
                              QMap<QString, InterfaceProperties> &supportedInterfaces)
{
    if (ecudoc.isNull()
            || ecudoc->m_elAttrcats.isNull()
            || ecudoc->m_elDefatts.isNull()) {
        return;
    }

    supportedInterfaces.clear();
    const auto &attrcats = ecudoc->m_elAttrcats->m_elAttrcats;
    const auto &ecuatts = ecudoc->m_elDefatts->m_elEcuatts;

    for (const auto &def : ecuatts->m_elEnumdefs) {
        if (def.isNull()) continue;

        const auto &attrcatRef = def->m_attrcatref;
        if (attrcats.contains(attrcatRef)) {
            const auto &attrcat = attrcats.value(attrcatRef);
            const auto &categoryQual = attrcat->m_elQual->m_text;
            if (categoryQual == "COM.INTERFACES") {
                const auto &etags = def->elETags();
                const auto &qual = def->m_elQual->m_text;

                //qDebug() << "ENUM INF" << qual;

                bool isSupported = false;
                if (etags.contains(def->v())) {
                    isSupported = (etags.value(def->v()) == "supported");
                }

                InterfaceProperties ipr;
                ipr.m_qual = qual;
                ipr.m_name = def->m_elName->getValue();
                ipr.m_isSupported = isSupported;

                supportedInterfaces.insert(qual, ipr);
            }
        }
    }
}

void parseServiceOfDiagInst(const QSharedPointer<CDDDbECUDOC> &ecudoc,
                            const QSharedPointer<CDDDbDIAGINST> &inst,
                            QMap<QString, ServiceProperties> &services)
{
    if (inst.isNull())
        return;

    //services.clear();
    for (const auto &service : inst->m_elServices) {
        ServiceProperties spr;
        spr.m_qual = service->m_elQual->m_text;
        spr.m_name = service->m_elShortcutname->getValue();

        services.insert(spr.m_name, spr);
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
    //parseInterfaceParameters(m_ecudoc, m_interfaceParameters, m_supportedInterfaces);
    parseSupportedInterfaces(m_ecudoc, m_supportedInterfaces);
}



QMap<QString, CDDDatabase::InterfaceParameters> CDDDatabase::getInterfaceParameters(const QString &interfaceName) const
{
    QMap<QString, CDDDatabase::InterfaceParameters> interfaceParameters;

    const auto &ecudoc = m_ecudoc;
    if (ecudoc.isNull()
            || ecudoc->m_elEcu.isNull()
            || ecudoc->m_elAttrcats.isNull()
            || ecudoc->m_elDefatts.isNull()) {
        return interfaceParameters;
    }

    QString qualPrefix = interfaceName + '.';
    const auto &attrcats = ecudoc->m_elAttrcats->m_elAttrcats;
    const auto &ecuatts = ecudoc->m_elDefatts->m_elEcuatts;

    for (const auto &def : ecuatts->m_elUnsdefs) {
        if (def.isNull()) continue;

        const auto &qual = def->m_elQual->m_text;
        if (qual.startsWith(qualPrefix)) {
            InterfaceParameters ipr;
            ipr.m_qual = qual;
            ipr.m_name = def->m_elName->getValue();
            ipr.m_category = getCategory<CDDDbUNSDEF>(def, attrcats);
            ipr.m_type = CDDAttrType::eUNSIGNED;
            ipr.m_value = def->m_v.toUInt();
            ipr.m_displayFormat = (def->m_df == "dec")?CDDUnsignedDataFormat::eDEC:CDDUnsignedDataFormat::eHEX;
            interfaceParameters.insert(qual, ipr);
        }
    }

    for (const auto &def : ecuatts->m_elEnumdefs) {
        if (def.isNull()) continue;

        const auto &qual = def->m_elQual->m_text;
        if (qual.startsWith(qualPrefix)) {
            InterfaceParameters ipr;
            ipr.m_qual = qual;
            ipr.m_name = def->m_elName->getValue();
            ipr.m_category = getCategory<CDDDbENUMDEF>(def, attrcats);
            ipr.m_type = CDDAttrType::eENUM;
            ipr.m_value = def->m_v.toUInt();
            const auto &etags = def->elETags();
            for (auto it = etags.begin(); it != etags.end(); ++it) {
                ipr.m_enumTable.insert(it.key().toUInt(), it.value());
            }
            interfaceParameters.insert(qual, ipr);
        }
    }

    for (const auto &def : ecuatts->m_elCstrdefs) {
        if (def.isNull()) continue;

        const auto &qual = def->m_elQual->m_text;
        if (qual.startsWith(qualPrefix)) {
            InterfaceParameters ipr;
            ipr.m_qual = qual;
            ipr.m_name = def->m_elName->getValue();
            ipr.m_category = getCategory<CDDDbCSTRDEF>(def, attrcats);
            ipr.m_type = CDDAttrType::eCSTR;
            ipr.m_value = 0;
            ipr.m_enumTable.insert(0, def->m_elCommonstring->m_text);
            interfaceParameters.insert(qual, ipr);
        }
    }

    for (const auto &def : ecuatts->m_elStrdefs) {
        if (def.isNull()) continue;

        const auto &qual = def->m_elQual->m_text;
        if (qual.startsWith(qualPrefix)) {
            InterfaceParameters ipr;
            ipr.m_qual = qual;
            ipr.m_name = def->m_elName->getValue();
            ipr.m_category = getCategory<CDDDbSTRDEF>(def, attrcats);
            ipr.m_type = CDDAttrType::eSTR;
            ipr.m_value = 0;
            ipr.m_enumTable.insert(0, def->m_elString->getValue());
            interfaceParameters.insert(qual, ipr);
        }
    }

    // update values defined in ECU node
    const auto &ecuUnss = ecudoc->m_elEcu->m_elUnss;
    for (const auto &uns : ecuUnss) {
        const QString &ecuattrRef = uns->m_attrref;
        if (ecuatts->m_elUnsdefs.contains(ecuattrRef)) {
            const auto &def = ecuatts->m_elUnsdefs.value(ecuattrRef);
            const auto &qual = def->m_elQual->m_text;
            if (interfaceParameters.contains(qual)) {
                interfaceParameters[qual].m_value = uns->m_v.toUInt();
            }
        }
    }

    const auto &ecuEnums = ecudoc->m_elEcu->m_elEnums;
    for (const auto &ecuDef : ecuEnums) {
        const QString &ecuattrRef = ecuDef->m_attrref;
        if (ecuatts->m_elEnumdefs.contains(ecuattrRef)) {
            const auto &def = ecuatts->m_elEnumdefs.value(ecuattrRef);
            const auto &qual = def->m_elQual->m_text;
            if (interfaceParameters.contains(qual)) {
                interfaceParameters[qual].m_value = ecuDef->m_v.toUInt();
            }
        }
    }

    const auto &ecuCstrs = ecudoc->m_elEcu->m_elCstrs;
    for (const auto &ecuDef : ecuCstrs) {
        const QString &ecuattrRef = ecuDef->m_attrref;
        if (ecuatts->m_elCstrdefs.contains(ecuattrRef)) {
            const auto &def = ecuatts->m_elCstrdefs.value(ecuattrRef);
            const auto &qual = def->m_elQual->m_text;
            if (interfaceParameters.contains(qual)) {
                interfaceParameters[qual].m_enumTable[0] = ecuDef->m_elCommonstring->m_text;
            }
        }
    }

    return interfaceParameters;
}

QVector<CDDDatabase::DiagClassProperties_t> CDDDatabase::getDiagnosticClasses(const QString &varQual) const
{
    QVector<CDDDatabase::DiagClassProperties_t> diagnosticClasses;

    const auto &ecudoc = m_ecudoc;
    if (ecudoc.isNull()
            || ecudoc->m_elEcu.isNull()) {
        return diagnosticClasses;
    }

    const auto &dcltmplsSorted = ecudoc->m_elDcltmpls->m_elDcltmplVector;
    for (const auto &dcltmpl : dcltmplsSorted) {
        DiagClassProperties_t dcpr;
        dcpr.m_qual = dcltmpl->m_elQual->m_text;
        dcpr.m_name = dcltmpl->m_elName->getValue();

        diagnosticClasses.append(dcpr);
    }

    QSharedPointer<CDDDbVAR> var;
    const auto &vars = ecudoc->m_elEcu->m_elVars;
    for (auto it = vars.begin(); it != vars.end(); ++it) {
        auto &v = it.value();
        if (v->m_elQual->m_text == varQual) {
            var = v;
            break;
        }
    }

    if (var.isNull()) {
        return diagnosticClasses;
    }

    const auto &dcltmpls = ecudoc->m_elDcltmpls->m_elDcltmpls;
    const auto &diagClasses = var->m_elDiagclasss;
    for (const auto &diagClass : diagClasses) {
        const auto &tmplRef = diagClass->m_tmplref;
        if (dcltmpls.contains(tmplRef)) {
            const auto &dcltmpl = dcltmpls.value(tmplRef);
            const auto &key = dcltmpl->m_id;
//            diagnosticClasses[key].m_isSupported = true;
//            diagnosticClasses[key].m_diagInsts = diagClass->m_elDiaginsts;
        }
    }

    for (const auto &diagInst : var->m_elDiaginsts) {
        const auto &tmplRef = diagInst->m_tmplref;
        if (dcltmpls.contains(tmplRef)) {
            const auto &dcltmpl = dcltmpls.value(tmplRef);
            const auto &key = dcltmpl->m_id;
//            diagnosticClasses[key].m_isSupported = true;
//            diagnosticClasses[key].m_diagInsts.insert(diagInst->m_id, diagInst);
        }
    }

    for (const auto &cl : diagnosticClasses) {
        qDebug() << cl;
    }

#if 0
    QMap<QString, ServiceProperties> services;

    const auto &diagClasses = var->m_elDiagclasss;
    for (const auto &diagClass : diagClasses) {
        for (const auto &diagInst : diagClass->m_elDiaginsts) {
            parseServiceOfDiagInst(ecudoc, diagInst, services);
        }
    }

    for (const auto &diagInst : var->m_elDiaginsts) {
        parseServiceOfDiagInst(ecudoc, diagInst, services);
    }

    for (const auto &service : services) {
        qDebug() << service.m_name;
    }
#endif

    return diagnosticClasses;
}

} // namespace cdd
} // namespace vector

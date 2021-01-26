#pragma once

#include "CDDExport.h"
#include "CDDTypes.h"
#include "CDDDbIncludes.h"

namespace vector {
namespace cdd {

//class CDDDbECUDOC;
//class CDDDbENUMDEF;

class VECTOR_CDD_API CDDDatabase
{
public:
    CDDDatabase();
    ~CDDDatabase();

    /** load from XML DOM element */
    void load(const QDomElement &element);

    /** element ECUDOC */
    QSharedPointer<CDDDbECUDOC> m_ecudoc;

public:
    typedef struct InterfaceProperties_t {
        QString m_qual;
        QString m_name;
        bool m_isSupported;
    } InterfaceProperties;

    typedef struct InterfaceParameters_t {
        QString getEnumString() const
        {
            if (m_enumTable.contains(m_value)) {
                return m_enumTable[m_value];
            }
            return QString();
        }

        QString getCStrString() const
        {
            return m_enumTable[0];
        }

        QString m_qual;
        QString m_name;
        QString m_category;
        CDDAttrType m_type;
        CDDUnsignedDataFormat m_displayFormat;
        quint32 m_value{0};
        QMap<quint32, QString> m_enumTable;
    } InterfaceParameters;

    typedef struct DiagClassProperties_t {
        QString m_qual;
        QString m_name;
        bool m_isSupported{false};
        QMap<QString, QSharedPointer<CDDDbDIAGINST>> m_diagInsts;
    } DiagClassProperties;

    typedef struct ServiceProperties_t {
        QString m_qual;
        QString m_name;
        bool m_isSupported{false};
    } ServiceProperties;

    void parse();

    bool isEcuEnumDefValid() const
    {
        return (m_ecudoc.isNull()
                || m_ecudoc->m_elDefatts.isNull()
                || m_ecudoc->m_elDefatts->m_elEcuatts.isNull()
                || !m_ecudoc->m_elDefatts->m_elEcuatts->m_elEnumdefs.isEmpty());
    }

    QMap<QString, QSharedPointer<CDDDbENUMDEF>> &getEcuEnumDefs() const
    {
        return m_ecudoc->m_elDefatts->m_elEcuatts->m_elEnumdefs;
    }

    bool isEcuUnsDefValid() const
    {
        return (m_ecudoc.isNull()
                || m_ecudoc->m_elDefatts.isNull()
                || m_ecudoc->m_elDefatts->m_elEcuatts.isNull()
                || !m_ecudoc->m_elDefatts->m_elEcuatts->m_elUnsdefs.isEmpty());
    }

    QMap<QString, QSharedPointer<CDDDbUNSDEF>> &getEcuUnsDefs() const
    {
        return m_ecudoc->m_elDefatts->m_elEcuatts->m_elUnsdefs;
    }

    /*!
     * \brief getSupportedInterfaces
     * \return  QMap<interfaceName, isSupported>
     */
    const QMap<QString, InterfaceProperties> &getSupportedInterfaces() const {return m_supportedInterfaces;}
    QMap<QString, InterfaceParameters> getInterfaceParameters(const QString &interfaceName) const;
    QVector<CDDDatabase::DiagClassProperties_t> getDiagnosticClasses(const QString &varQual) const;

private:
    QMap<QString, InterfaceProperties> m_supportedInterfaces;
    QMap<QString, InterfaceParameters> m_interfaceParameters;
};

QDebug inline operator<<(QDebug d, const CDDDatabase::InterfaceProperties &o)
{
    QDebugStateSaver saver(d);
    d.nospace().noquote() << "InterfaceProperties: ("
                          << "q:" << o.m_qual << ","
                          << "n:" << o.m_name << ","
                          << "s:" << o.m_isSupported
                          << ")";

    return d;
}

QDebug inline operator<<(QDebug d, const CDDDatabase::InterfaceParameters &o)
{
    QDebugStateSaver saver(d);
    d.nospace().noquote() << "InterfaceParameters: ("
                          << "q:" << o.m_qual << ","
                          << "n:" << o.m_name << ","
                          << "c:" << o.m_category << ","
                          << "t:" << static_cast<quint32>(o.m_type) << ","
                          << "p:" << static_cast<quint32>(o.m_displayFormat) << ","
                          << "v:" << o.m_value << ","
                          << "m:" << o.m_enumTable
                          << ")";

    return d;
}

QDebug inline operator<<(QDebug d, const CDDDatabase::ServiceProperties &o)
{
    QDebugStateSaver saver(d);
    d.nospace().noquote() << "ServiceProperties: ("
                          << "q:" << o.m_qual << ","
                          << "n:" << o.m_name
                          << ")";

    return d;
}

QDebug inline operator<<(QDebug d, const CDDDatabase::DiagClassProperties &o)
{
    QDebugStateSaver saver(d);
    d.nospace().noquote() << "DiagClassProperties: ("
                          << "q:" << o.m_qual << ","
                          << "n:" << o.m_name << ","
                          << "s:" << o.m_isSupported << ","
                          << "c:" << o.m_diagInsts.count()
                          << ")";

    return d;
}

} // namespace cdd
} // namespace vector

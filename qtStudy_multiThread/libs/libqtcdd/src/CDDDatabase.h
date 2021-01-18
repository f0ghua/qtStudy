#pragma once

#include "CDDExport.h"
#include "CDDTypes.h"

namespace vector {
namespace cdd {

class CDDDbECUDOC;

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
    //using InterfaceMapT = QMap<QString, bool>;
    typedef struct InterfaceParameter_t {
        QString m_name;
        QString m_category;
        CDDAttrType m_type;
        CDDUnsignedDataFormat m_displayFormat;
        quint32 m_value;
        QMap<quint32, QString> m_enumTable;
    } InterfaceParameter;

    void parse();

    /*!
     * \brief getSupportedInterfaces
     * \return  QMap<interfaceName, isSupported>
     */
    const QMap<QString, bool> &getSupportedInterfaces() const {return m_supportedInterfaces;}
    const QMap<QString, InterfaceParameter> &getInterfaceParameters() const {return m_interfaceParameters;};

private:
    QMap<QString, bool> m_supportedInterfaces;
    QMap<QString, InterfaceParameter> m_interfaceParameters;
};

QDebug inline operator<<(QDebug d, const CDDDatabase::InterfaceParameter &o)
{
    QDebugStateSaver saver(d);
    d.nospace().noquote() << "InterfaceParameter: ("
                          << "n:" << o.m_name << ","
                          << "c:" << o.m_category << ","
                          << "t:" << static_cast<quint32>(o.m_type) << ","
                          << "p:" << static_cast<quint32>(o.m_displayFormat) << ","
                          << "v:" << o.m_value << ","
                          << "m:" << o.m_enumTable
                          << ")";

    return d;
}

} // namespace cdd
} // namespace vector

#include "Fibex.h"

namespace ASAM {
namespace FIBEX {

Fibex::Fibex(QObject *parent)
    : FXFibex(parent)
    , m_domElement(nullptr)
{

}

Fibex::~Fibex()
{

}

bool Fibex::covertXml2Db()
{
    return true;
}

bool Fibex::load(const QDomElement &element)
{   
    bool ret;

    /* load Fibex tree */
    ret = FXFibex::load(element);
    if (!ret) {
        return false;
    }

    return covertXml2Db();
}

} // FIBEX
} // ASAM

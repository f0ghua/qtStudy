#include "Fibex.h"

namespace ASAM {
namespace FIBEX {

Fibex::Fibex()
    : FXFibex()
    , m_domElement(nullptr)
{

}

Fibex::~Fibex()
{

}

bool Fibex::load(const QDomElement &element)
{   
    /* load Fibex tree */
    return FXFibex::load(element);
}

}
}

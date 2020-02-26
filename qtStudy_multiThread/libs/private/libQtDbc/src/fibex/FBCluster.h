#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

#include "FibexTypes.h"

namespace ASAM {
namespace FIBEX {

class VECTOR_DBC_EXPORT FBCluster : public QObject
{
public:
    FBCluster(QObject *parent);

};

} // FIBEX
} // ASAM

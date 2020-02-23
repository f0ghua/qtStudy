#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

namespace ASAM {
namespace FIBEX {

/**
 * Attribute Value Type
 */
enum class FBAttributeValueType {
    Int,        /**< Integer */
    Hex,        /**< Hex */
    Float,      /**< Float */
    String,     /**< String */
    Enum        /**< Enum */
};

}
}

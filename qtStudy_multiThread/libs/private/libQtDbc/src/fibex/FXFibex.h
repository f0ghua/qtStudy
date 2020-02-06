#pragma once

#include "platform.h"
#include "vector_dbc_export.h"

#include "FXElements.h"

#if 0
#include "ProcessingInformation.h"
#include "ProjectType.h"
#include "Protocols.h"
#include "Requirements.h"
#include "VersionType.h"
#endif

#include "FXProcessingInformation.h"

namespace ASAM {
namespace FIBEX {

/**
 * @brief element FIBEX
 *
 * Root element
 */
class VECTOR_DBC_EXPORT FXFibex
{
public:
    FXFibex();

    /** load from XML DOM element */
    bool load(const QDomElement &element);

    /** element ELEMENTS */
    FXElements m_elements;

    /** element PROCESSING-INFORMATION */
    FXProcessingInformation m_processingInformation;

#if 0
    /**
     * element PROJECT
     *
     * The project/vehicle described in the referencing file
     */
    ProjectType project;

    /** element PROTOCOLS */
    std::list<Protocols> protocols;





    /** element REQUIREMENTS */
    std::list<Requirements> requirements;

    /**
     * attribute VERSION
     *
     * To identify the schemas version that should be applied on the referencing file.
     * Note that this value is fixed on the current schema version to avoid confusion checking old FIBEX instances against a new FIBEX schema or oposite.
     */
    VersionType version;
#endif

};

}
}

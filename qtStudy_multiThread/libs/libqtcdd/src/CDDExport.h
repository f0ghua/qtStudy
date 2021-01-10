#pragma once

#include <QtCore/qglobal.h>

#ifdef LIB_STATIC
#define VECTOR_CDD_API
#else
#if defined(QLIBCDD_LIBRARY)
#define VECTOR_CDD_API Q_DECL_EXPORT
#else
#define VECTOR_CDD_API Q_DECL_IMPORT
#endif
#endif

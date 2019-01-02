#pragma once

#include "hu/platform.h"

#ifndef __has_builtin
#define hu_has_builtin(x) 0
#else
#define hu_has_builtin __has_builtin
#endif

#ifndef __has_include
#define hu_has_include(x) 0
#else
#define hu_has_include __has_include
#endif

#ifndef __has_feature
#define hu_has_feature(x) 0
#else
#define hu_has_feature __has_feature
#endif

#ifndef __has_extension
#define hu_has_extension hu_has_feature
#else
#define hu_has_extension __has_extension
#endif

#if HU_COMP_GNULIKE_P || hu_has_builtin(__builtin_expect)
#define likely(x) __builtin_expect(!!(x), 1)
#define unlikely(x) __builtin_expect(!!(x), 0)
#else
#define likely(x) !!(x)
#define unlikely(x) !!(x)
#endif

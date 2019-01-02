#ifndef HU_MACROS_H
#define HU_MACROS_H 1

#include <hu/platform.h>

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

#ifndef __has_attribute
#define hu_has_attribute(x) 0
#else
#define hu_has_attribute __has_attribute
#endif

#if HU_COMP_GNULIKE_P || hu_has_builtin(__builtin_expect)
#define likely(x) __builtin_expect(!!(x), 1)
#define unlikely(x) __builtin_expect(!!(x), 0)
#else
#define likely(x) !!(x)
#define unlikely(x) !!(x)
#endif

#if HU_COMP_GNULIKE_P || hu_has_attribute(always_inline)
#define HU_FORCE_INLINE __attribute__((always_inline))
#elif HU_COMP_MSVC_P
#define HU_FORCE_INLINE __forceinline
#else
#define HU_FORCE_INLINE
#endif

#if HU_COMP_GNULIKE_P || hu_has_attribute(noinline)
#define HU_NOINLINE __attribute__((noinline))
#elif HU_COMP_MSVC_P
#define HU_NOINLINE __declspec(noinline)
#else
#define HU_NOINLINE
#endif

#if HU_COMP_GNULIKE_P || hu_has_attribute(visibility)
#define HU_LIB_EXPORT __attribute__((visibility("default")))
#define HU_LIB_IMPORT HU_LIB_EXPORT
#elif HU_COMP_MSVC_P
#define HU_LIB_EXPORT __declspec(dllexport)
#define HU_LIB_IMPORT __declspec(dllimport)
#else
#define HU_LIB_EXPORT
#define HU_LIB_IMPORT
#endif

#endif

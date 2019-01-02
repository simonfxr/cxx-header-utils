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
#define hu_likely(x) __builtin_expect(!!(x), 1)
#define hu_unlikely(x) __builtin_expect(!!(x), 0)
#else
#define hu_likely(x) !!(x)
#define hu_unlikely(x) !!(x)
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

#if HU_CXX_11_P
#define HU_NORETURN [[noreturn]]
#else
#if HU_COMP_GNULIKE_P || hu_has_attribute(noreturn)
#define HU_NORETURN __attribute__((noreturn))
#elif HU_COMP_MSVC_P
#define HU_NORETURN
#else
#define HU_NORETURN
#endif
#endif

#if HU_CXX_17_P
#define HU_NODISCARD [[nodiscard]]
#else
#if HU_COMP_GNULIKE_P || hu_has_attribute(warn_unused_result)
#define HU_NODISCARD __attribute__((warn_unused_result))
#elif HU_COMP_MSVC_P && _MSC_VER >= 1700
#define HU_NODISCARD _Check_return_
#else
#define HU_NODISCARD
#endif
#endif

#if HU_CXX_14_P
#define HU_DEPRECATED [[deprecated]]
#else
#if HU_COMP_GNULIKE_P || hu_has_attribute(deprecated)
#define HU_DEPRECATED __attribute__((deprecated))
#elif HU_COMP_MSVC_P
#define HU_DEPRECATED __declspec(deprecated)
#else
#define HU_DEPRECATED
#endif
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

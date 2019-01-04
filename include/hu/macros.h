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
#define HU_HAVE_likely_P 1
#define HU_HAVE_unlikely_P 1
#else
#define hu_likely(x) !!(x)
#define hu_unlikely(x) !!(x)
#define HU_HAVE_likely_P 0
#define HU_HAVE_unlikely_P 0
#endif

#if HU_HAVE_likely_P
#define HU_HAVE_likely 1
#endif

#if HU_HAVE_unlikely_P
#define HU_HAVE_unlikely 1
#endif

#if HU_COMP_GNULIKE_P || hu_has_attribute(always_inline)
#define HU_FORCE_INLINE __attribute__((always_inline))
#define HU_HAVE_FORCE_INLINE_P 1
#elif HU_COMP_MSVC_P
#define HU_FORCE_INLINE __forceinline
#define HU_HAVE_FORCE_INLINE_P 1
#else
#define HU_FORCE_INLINE
#define HU_HAVE_FORCE_INLINE_P 0
#endif

#if HU_HAVE_FORCE_INLINE_P
#define HU_HAVE_FORCE_INLINE 1
#endif

#if HU_COMP_GNULIKE_P || hu_has_attribute(noinline)
#define HU_HAVE_NOINLINE_P 1
#define HU_NOINLINE __attribute__((noinline))
#elif HU_COMP_MSVC_P
#define HU_HAVE_NOINLINE_P 1
#define HU_NOINLINE __declspec(noinline)
#else
#define HU_HAVE_NOINLINE_P 0
#define HU_NOINLINE
#endif

#if HU_HAVE_NOINLINE_P
#define HU_HAVE_NOINLINE 1
#endif

#if HU_CXX_11_P
#define HU_NORETURN [[noreturn]]
#define HU_HAVE_NORETURN_P 1
#else
#if HU_COMP_GNULIKE_P || hu_has_attribute(noreturn)
#define HU_NORETURN __attribute__((noreturn))
#define HU_HAVE_NORETURN_P 1
#elif HU_COMP_MSVC_P
#define HU_NORETURN __declspec(noreturn)
#define HU_HAVE_NORETURN_P 1
#else
#define HU_NORETURN
#define HU_HAVE_NORETURN_P 0
#endif
#endif

#if HU_HAVE_NORETURN_P
#define HU_HAVE_NORETURN 1
#endif

#if HU_CXX_17_P
#define HU_NODISCARD [[nodiscard]]
#define HU_HAVE_NODISCARD_P 1
#else
#if HU_COMP_GNULIKE_P || hu_has_attribute(warn_unused_result)
#define HU_NODISCARD __attribute__((warn_unused_result))
#define HU_HAVE_NODISCARD_P 1
#elif HU_COMP_MSVC_P && _MSC_VER >= 1700
#define HU_NODISCARD _Check_return_
#define HU_HAVE_NODISCARD_P 1
#else
#define HU_NODISCARD
#define HU_HAVE_NODISCARD_P 0
#endif
#endif

#if HU_HAVE_NODISCARD_P
#define HU_HAVE_NODISCARD 1
#endif

#if HU_CXX_14_P
#define HU_HAVE_DEPRECATED_P 1
#define HU_DEPRECATED [[deprecated]]
#else
#if HU_COMP_GNULIKE_P || hu_has_attribute(deprecated)
#define HU_HAVE_DEPRECATED_P 1
#define HU_DEPRECATED __attribute__((deprecated))
#elif HU_COMP_MSVC_P
#define HU_HAVE_DEPRECATED_P 1
#define HU_DEPRECATED __declspec(deprecated)
#else
#define HU_HAVE_DEPRECATED_P 0
#define HU_DEPRECATED
#endif
#endif

#if HU_HAVE_DEPRECATED_P
#define HU_HAVE_DEPRECATED 1
#endif

#if HU_COMP_GNULIKE_P || hu_has_attribute(visibility)
#define HU_HAVE_LIB_EXPORT_P 1
#define HU_HAVE_LIB_IMPORT_P 1
#define HU_LIB_EXPORT __attribute__((visibility("default")))
#define HU_LIB_IMPORT HU_LIB_EXPORT
#elif HU_COMP_MSVC_P
#define HU_HAVE_LIB_EXPORT_P 1
#define HU_HAVE_LIB_IMPORT_P 1
#define HU_LIB_EXPORT __declspec(dllexport)
#define HU_LIB_IMPORT __declspec(dllimport)
#else
#define HU_HAVE_LIB_EXPORT_P 0
#define HU_HAVE_LIB_IMPORT_P 0
#define HU_LIB_EXPORT
#define HU_LIB_IMPORT
#endif

#if HU_HAVE_LIB_EXPORT_P
#define HU_HAVE_LIB_EXPORT 1
#endif

#if HU_HAVE_LIB_IMPORT_P
#define HU_HAVE_LIB_IMPORT 1
#endif

#if HU_COMP_GNULIKE_P || hu_has_attribute(aligned)
#define HU_HAVE_ALIGN_P 1
#define HU_ALIGN(n) __attribute__((aligned(n)))
#elif HU_COMP_MSVC_P
#define HU_HAVE_ALIGN_P 1
#define HU_ALIGN(n) __declspec(align(n))
#else
#define HU_HAVE_ALIGN_P 0
#define HU_ALIGN(n)
#endif

#if HU_HAVE_ALIGN_P
#define HU_HAVE_ALIGN 1
#endif

#if HU_COMP_GNULIKE_P
#define HU_HAVE_RESTRICT_P 1
#define HU_RESTRICT __restrict__
#elif HU_COMP_MSVC_P
#define HU_HAVE_RESTRICT_P 1
#define HU_RESTRICT __restrict
#else
#define HU_HAVE_RESTRICT_P 0
#define HU_RESTRICT
#endif

#if HU_HAVE_RESTRICT_P
#define HU_HAVE_RESTRICT 1
#endif

#if HU_COMP_GNULIKE_P || hu_has_attribute(packed)
#define HU_HAVE_PACKED_P 1
#define HU_BEGIN_PACKED
#define HU_END_PACKED
#define HU_PACKED __attribute__((packed))
#elif HU_COMP_MSVC_P
#define HU_HAVE_PACKED_P 1
#define HU_BEGIN_PACKED __pragma(pack(push, 1))
#define HU_END_PACKED __pragma(pack(pop))
#define HU_PACKED
#else
#define HU_HAVE_PACKED_P 0
#define HU_BEGIN_PACKED
#define HU_END_PACKED
#define HU_PACKED
#endif

#if HU_HAVE_PACKED_P
#define HU_HAVE_PACKED 1
#endif

#endif

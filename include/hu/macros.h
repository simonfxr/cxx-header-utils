#ifndef HU_MACROS_H
#define HU_MACROS_H 1

#include <hu/platform.h>

#define HU_HAVE_FORCE_INLINE_P 0
#define HU_HAVE_DEPRECATED_P 0
#define HU_HAVE_NOINLINE_P 0
#define HU_HAVE_NORETURN_P 0
#define HU_HAVE_NODISCARD_P 0
#define HU_HAVE_LIB_EXPORT_P 0
#define HU_HAVE_LIB_IMPORT_P 0
#define HU_HAVE_ALIGN_P 0
#define HU_HAVE_RESTRICT_P 0
#define HU_HAVE_PACKED_P 0
#define HU_HAVE_CONST_FN_P 0
#define HU_HAVE_PURE_P 0

#define HU_HAVE_likely_P 0
#define HU_HAVE_unlikely_P 0
#define HU_HAVE_constant_p_P 0
#define HU_HAVE_assume_P 0
#define HU_HAVE_assume_unreachable_P 0
#define HU_HAVE_assume_aligned_P 0

#define HU_CAT_I(x, y) x##y
#define HU_CAT(x, y) HU_CAT_I(x, y)

#define HU_TOSTR_I(x) #x
#define HU_TOSTR(x) HU_TOSTR_I(x)

#if HU_CXX_P
#define HU_BOOL_CONTEXT(p) bool(p)
#define HU_BOOL_TRUE true
#define HU_BOOL_FALSE false
#else
#define HU_BOOL_CONTEXT(p) (!!(p))
#define HU_BOOL_TRUE 1
#define HU_BOOL_FALSE 0
#endif

#ifndef __has_builtin
#define HU_HAVE_has_builtin_P 0
#define hu_has_builtin(x) 0
#else
#define HU_HAVE_has_builtin_P 1
#define HU_HAVE_has_builtin 1
#define hu_has_builtin __has_builtin
#endif

#ifndef __has_include
#define HU_HAVE_has_include_P 0
#define hu_has_include(x) 0
#else
#define HU_HAVE_has_include_P 1
#define HU_HAVE_has_include 1
#define hu_has_include __has_include
#endif

#ifndef __has_include_next
#define HU_HAVE_has_include_next_P 0
#define hu_has_include_next(x) 0
#else
#define HU_HAVE_has_include_next_P 1
#define HU_HAVE_has_include_next 1
#define hu_has_include_next __has_include_next
#endif

#ifndef __has_feature
#define HU_HAVE_has_feature_P 0
#define hu_has_feature(x) 0
#else
#define HU_HAVE_has_feature_P 1
#define HU_HAVE_has_feature 1
#define hu_has_feature __has_feature
#endif

#ifndef __has_extension
#define HU_HAVE_has_extension_P 0
#define hu_has_extension hu_has_feature
#else
#define HU_HAVE_has_extension_P 1
#define HU_HAVE_has_extension 1
#define hu_has_extension __has_extension
#endif

#ifndef __has_attribute
#define HU_HAVE_has_attribute_P 0
#define hu_has_attribute(x) 0
#else
#define HU_HAVE_has_attribute_P 1
#define HU_HAVE_has_attribute 1
#define hu_has_attribute __has_attribute
#endif

#ifndef __has_declspec_attribute
#define HU_HAVE_has_declspec_attribute_P 0
#define hu_has_declspec_attribute(x) 0
#else
#define HU_HAVE_has_declspec_attribute_P 1
#define HU_HAVE_has_declspec_attribute 1
#define hu_has_declspec_attribute __has_declspec_attribute
#endif

#if HU_COMP_GNULIKE_P || hu_has_attribute(always_inline)
#define HU_FORCE_INLINE __attribute__((always_inline))
#undef HU_HAVE_FORCE_INLINE_P
#define HU_HAVE_FORCE_INLINE_P 1
#elif HU_COMP_MSVC_P
#define HU_FORCE_INLINE __forceinline
#undef HU_HAVE_FORCE_INLINE_P
#define HU_HAVE_FORCE_INLINE_P 1
#else
#define HU_FORCE_INLINE
#endif

#if HU_HAVE_FORCE_INLINE_P
#define HU_HAVE_FORCE_INLINE 1
#endif

#if HU_COMP_GNULIKE_P || hu_has_attribute(noinline)
#undef HU_HAVE_NOINLINE_P
#define HU_HAVE_NOINLINE_P 1
#define HU_NOINLINE __attribute__((noinline))
#elif HU_COMP_MSVC_P || hu_has_declspec_attribute(noinline)
#undef HU_HAVE_NOINLINE_P
#define HU_HAVE_NOINLINE_P 1
#define HU_NOINLINE __declspec(noinline)
#else
#define HU_NOINLINE
#endif

#if HU_HAVE_NOINLINE_P
#define HU_HAVE_NOINLINE 1
#endif

#if HU_CXX_11_P
#undef HU_HAVE_NORETURN_P
#define HU_HAVE_NORETURN_P 1
#define HU_NORETURN [[noreturn]]
#else
#if HU_COMP_GNULIKE_P || hu_has_attribute(noreturn)
#undef HU_HAVE_NORETURN_P
#define HU_HAVE_NORETURN_P 1
#define HU_NORETURN __attribute__((noreturn))
#elif HU_COMP_MSVC_P || hu_has_declspec_attribute(noreturn)
#undef HU_HAVE_NORETURN_P
#define HU_HAVE_NORETURN_P 1
#define HU_NORETURN __declspec(noreturn)
#else
#define HU_NORETURN
#endif
#endif

#if HU_HAVE_NORETURN_P
#define HU_HAVE_NORETURN 1
#endif

#if HU_CXX_17_P
#undef HU_HAVE_NODISCARD_P
#define HU_HAVE_NODISCARD_P 1
#define HU_NODISCARD [[nodiscard]]
#else
#if HU_COMP_GNULIKE_P || hu_has_attribute(warn_unused_result)
#undef HU_HAVE_NODISCARD_P
#define HU_HAVE_NODISCARD_P 1
#define HU_NODISCARD __attribute__((warn_unused_result))
#elif HU_COMP_MSVC_P && _MSC_VER >= 1700
#undef HU_HAVE_NODISCARD_P
#define HU_HAVE_NODISCARD_P 1
#define HU_NODISCARD _Check_return_
#else
#define HU_NODISCARD
#endif
#endif

#if HU_HAVE_NODISCARD_P
#define HU_HAVE_NODISCARD 1
#endif

#if HU_CXX_14_P
#undef HU_HAVE_DEPRECATED_P
#define HU_HAVE_DEPRECATED_P 1
#define HU_DEPRECATED [[deprecated]]
#else
#if HU_COMP_GNULIKE_P || hu_has_attribute(deprecated)
#undef HU_HAVE_DEPRECATED_P
#define HU_HAVE_DEPRECATED_P 1
#define HU_DEPRECATED __attribute__((deprecated))
#elif HU_COMP_MSVC_P || hu_has_declspec_attribute(deprecated)
#undef HU_HAVE_DEPRECATED_P
#define HU_HAVE_DEPRECATED_P 1
#define HU_DEPRECATED __declspec(deprecated)
#else
#define HU_DEPRECATED
#endif
#endif

#if HU_HAVE_DEPRECATED_P
#define HU_HAVE_DEPRECATED 1
#endif

#if HU_COMP_GNULIKE_P || hu_has_attribute(visibility)
#undef HU_HAVE_LIB_EXPORT_P
#undef HU_HAVE_LIB_IMPORT_P
#define HU_HAVE_LIB_EXPORT_P 1
#define HU_HAVE_LIB_IMPORT_P 1
#define HU_LIB_EXPORT __attribute__((visibility("default")))
#define HU_LIB_IMPORT HU_LIB_EXPORT
#elif HU_COMP_MSVC_P || (hu_has_declspec_attribute(dllexport) &&               \
                         hu_has_declspec_attribute(dllimport))
#undef HU_HAVE_LIB_EXPORT_P
#undef HU_HAVE_LIB_IMPORT_P
#define HU_HAVE_LIB_EXPORT_P 1
#define HU_HAVE_LIB_IMPORT_P 1
#define HU_LIB_EXPORT __declspec(dllexport)
#define HU_LIB_IMPORT __declspec(dllimport)
#else
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
#undef HU_HAVE_ALIGN_P
#define HU_HAVE_ALIGN_P 1
#define HU_ALIGN(n) __attribute__((aligned(n)))
#elif HU_COMP_MSVC_P || hu_has_declspec_attribute(align)
#undef HU_HAVE_ALIGN_P
#define HU_HAVE_ALIGN_P 1
#define HU_ALIGN(n) __declspec(align(n))
#else
#define HU_ALIGN(n)
#endif

#if HU_HAVE_ALIGN_P
#define HU_HAVE_ALIGN 1
#endif

#if HU_COMP_GNULIKE_P || (defined(HU_C_VERS) && HU_C_VERS >= 1999)
#undef HU_HAVE_RESTRICT_P
#define HU_HAVE_RESTRICT_P 1
#define HU_RESTRICT __restrict__
#elif HU_COMP_MSVC_P
#undef HU_HAVE_RESTRICT_P
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
#undef HU_HAVE_PACKED_P
#define HU_HAVE_PACKED_P 1
#define HU_BEGIN_PACKED
#define HU_END_PACKED
#define HU_PACKED __attribute__((packed))
#elif HU_COMP_MSVC_P
#undef HU_HAVE_PACKED_P
#define HU_HAVE_PACKED_P 1
#define HU_BEGIN_PACKED __pragma(pack(push, 1))
#define HU_END_PACKED __pragma(pack(pop))
#define HU_PACKED
#else
#define HU_BEGIN_PACKED
#define HU_END_PACKED
#define HU_PACKED
#endif

#if HU_HAVE_PACKED_P
#define HU_HAVE_PACKED 1
#endif

#if HU_COMP_GNULIKE_P || hu_has_attribute(const)
#undef HU_HAVE_CONST_FN_P
#define HU_HAVE_CONST_FN_P 1
#define HU_CONST_FN __attribute__((const))
#else
#define HU_CONST_FN
#endif

#if HU_HAVE_CONST_FN_P
#define HU_HAVE_CONST_FN 1
#endif

#if HU_COMP_GNULIKE_P || hu_has_attribute(pure)
#undef HU_HAVE_PURE_P
#define HU_HAVE_PURE_P 1
#define HU_PURE __attribute__((pure))
#else
#define HU_PURE
#endif

#if HU_HAVE_PURE_P
#define HU_HAVE_PURE 1
#endif

#if HU_COMP_GNULIKE_P || hu_has_builtin(__builtin_expect)
#define hu_likely(x) __builtin_expect(HU_BOOL_CONTEXT(x), HU_BOOL_TRUE)
#define hu_unlikely(x) __builtin_expect(HU_BOOL_CONTEXT(x), HU_BOOL_FALSE)
#undef HU_HAVE_likely_P
#undef HU_HAVE_unlikely_P
#define HU_HAVE_likely_P 1
#define HU_HAVE_unlikely_P 1
#else
#define hu_likely(x) !!(x)
#define hu_unlikely(x) !!(x)
#endif

#if HU_HAVE_likely_P
#define HU_HAVE_likely 1
#endif

#if HU_HAVE_unlikely_P
#define HU_HAVE_unlikely 1
#endif

#if HU_COMP_GNULIKE_P || hu_has_builtin(__builtin_constant_p)
#undef HU_HAVE_constant_p_P
#define HU_HAVE_constant_p_P 1
#define hu_constant_p(x) __builtin_constant_p(x)
#else
#if HU_CXX_P
#define hu_constant_p(x) false
#else
#define hu_constant_p(x) 0
#endif
#endif

#if HU_HAVE_constant_p_P
#define HU_HAVE_constant_p 1
#endif

#if HU_COMP_GNULIKE_P || hu_has_builtin(__builtin_unreachable)
#undef HU_HAVE_assume_unreachable_P
#define HU_HAVE_assume_unreachable_P 1
#define hu_assume_unreachable() __builtin_unreachable()
#elif HU_COMP_MSVC_P
#undef HU_HAVE_assume_unreachable_P
#define HU_HAVE_assume_unreachable_P 1
#define hu_assume_unreachable() __assume(0)
#else
#define hu_assume_unreachable() ((void) 0)
#endif

#if HU_HAVE_assume_unreachable_P
#define HU_HAVE_assume_unreachable 1
#endif

#if hu_has_builtin(__builtin_assume)
#undef HU_HAVE_assume_P
#define HU_HAVE_assume_P 1
#define hu_assume(p) __builtin_assume(HU_BOOL_CONTEXT(p))
#elif HU_COMP_MSVC_P || HU_COMP_INTEL_P
#undef HU_HAVE_assume_P
#define HU_HAVE_assume_P 1
#define hu_assume(p) __assume(HU_BOOL_CONTEXT(p))
#elif HU_HAVE_assume_unreachable_P
#undef HU_HAVE_assume_P
#define HU_HAVE_assume_P 1
#define hu_assume(p)                                                           \
    do {                                                                       \
        if (!(p))                                                              \
            hu_assume_unreachable();                                           \
    } while (0)
#else
#define hu_assume(p) ((void) 0)
#endif

#if HU_HAVE_assume_P
#define HU_HAVE_assume 1
#endif

#if HU_COMP_GCC_P || HU_COMP_CLANG_P || hu_has_builtin(__builtin_assume_aligned)
#undef HU_HAVE_assume_aligned_P
#define HU_HAVE_assume_aligned_P 1
/* we only support the 2 argument version */
#define hu_assume_aligned(arg, algn) __builtin_assume_aligned(arg, algn)
#elif HU_COMP_INTEL_P
#undef HU_HAVE_assume_aligned_P
#define HU_HAVE_assume_aligned_P 1
#define hu_assume_aligned_helper(var, arg, algn)                               \
    ({                                                                         \
        __typeof__((arg)) var = (arg);                                         \
        __assume_aligned(var, algn);                                           \
        var;                                                                   \
    })
#define hu_assume_aligned(arg, algn)                                           \
    hu_assume_aligned_helper(                                                  \
      HU_PP_CAT(_hu_assume_aligned_tmp, __COUNTER__), arg, algn)
#else
#define hu_assume_aligned(arg, algn, ...) (arg)
#endif

#if HU_HAVE_assume_aligned_P
#define HU_HAVE_assume_aligned 1
#endif

#if HU_COMP_GNULIKE_P
#define HU_PRETTY_FUNCTION __PRETTY_FUNCTION__
#elif HU_COMP_MSVC_P
#define HU_PRETTY_FUNCTION __FUNCSIG__
#endif

#if HU_CXX_P

#if HU_CXX_VERS >= 2011
#define HU_STATIC_ASSERT_MSG(p, msg) static_assert(p, msg)
#if HU_CXX_VERS >= 2017
#define HU_STATIC_ASSERT(p) static_assert(p)
#endif
#endif

#elif HU_C_P

#if HU_C_VERS >= 2011
#define HU_STATIC_ASSERT_MSG(p, msg) _Static_assert(p, msg)
#if HU_C_VERS > 2017
#define HU_STATIC_ASSERT(p) _Static_assert(p)
#endif
#endif

#endif

#ifndef HU_STATIC_ASSERT_MSG
#define HU_STATIC_ASSERT_MSG(cond, _msg)                                       \
    typedef char HU_CAT(static_assertion_failed_at_line_,                      \
                        __LINE__)[(!!(cond)) * 2 - 1]
#endif

#ifndef HU_STATIC_ASSERT
#define HU_STATIC_ASSERT(cond) HU_STATIC_ASSERT_MSG(cond, "")
#endif

#endif

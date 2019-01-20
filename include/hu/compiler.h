#ifndef HU_COMPILER_H
#define HU_COMPILER_H

#define HU_COMP_GCC_P 0
#define HU_COMP_CLANG_P 0
#define HU_COMP_INTEL_P 0
#define HU_COMP_MSVC_P 0

#ifdef __clang__
#    undef HU_COMP_CLANG_P
#    define HU_COMP_CLANG_P 1
#elif defined(__ICC) || defined(__INTEL_COMPILER)
#    undef HU_COMP_INTEL_P
#    define HU_COMP_INTEL_P 1
#elif defined(__GNUC__)
#    undef HU_COMP_GCC_P
#    define HU_COMP_GCC_P 1
#endif

#ifdef _MSC_VER
#    undef HU_COMP_MSVC_P
#    define HU_COMP_MSVC_P 1
#endif

#if defined(__GNUC__) || defined(__clang__)
#    undef HU_COMP_GNULIKE_P
#    define HU_COMP_GNULIKE_P 1
#endif

#if HU_COMP_GCC_P || HU_COMP_CLANG_P || HU_COMP_INTEL_P
#    undef HU_COMP_GNULIKE_P
#    define HU_COMP_GNULIKE_P 1
#elif HU_COMP_MSVC_P
#    define HU_COMP_MSVC 1
#else
#    error "failed to detect compiler"
#endif

#if HU_COMP_GCC_P
#    define HU_COMP_GCC 1
#endif

#if HU_COMP_CLANG_P
#    define HU_COMP_CLANG 1
#endif

#if HU_COMP_INTEL_P
#    define HU_COMP_INTEL 1
#endif

#if HU_COMP_MSVC_P
#    define HU_COMP_MSVC 1
#endif

#if HU_COMP_GCC_P + HU_COMP_CLANG_P + HU_COMP_INTEL_P + HU_COMP_MSVC_P != 1
#    error "BUG: HU_COMP_*_P not properly defined"
#endif

#endif

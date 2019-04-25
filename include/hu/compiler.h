#ifndef HU_COMPILER_H
#define HU_COMPILER_H

#define HU_COMP_GCC_P 0
#define HU_COMP_CLANG_P 0
#define HU_COMP_INTEL_P 0
#define HU_COMP_MSVC_P 0

#define HU_MIN_VERSION(ax, ay, az, bx, by, bz)                                 \
    ((ax) *10000 + (ay) *100 + (az)) <= ((bx) *10000 + (by) *100 + (bz))

#define HU_GNUC_MIN_VERSION(x, y, z) 0
#define HU_CLANG_MIN_VERSION(x, y, z) 0
#define HU_INTEL_MIN_VERSION(x, y) 0
#define HU_CL_MIN_VERSION(x, y) 0

#ifdef __clang__
#    undef HU_COMP_CLANG_P
#    define HU_COMP_CLANG_P 1
#    undef HU_CLANG_MIN_VERSION
#    define HU_CLANG_MIN_VERSION(x, y, z)                                      \
        HU_MIN_VERSION(                                                        \
          x, y, z, __clang_major__, __clang_minor__, __clang_patchlevel__)
#elif defined(__ICC) || defined(__INTEL_COMPILER)
#    undef HU_COMP_INTEL_P
#    define HU_COMP_INTEL_P 1
#    undef HU_INTEL_MIN_VERSION
#    define HU_INTEL_MIN_VERSION(x, y) ((x) *100 + (y)) <= __INTEL_COMPILER
#elif defined(__GNUC__)
#    undef HU_COMP_GCC_P
#    define HU_COMP_GCC_P 1
#endif

#ifdef _MSC_VER
#    undef HU_COMP_MSVC_P
#    define HU_COMP_MSVC_P 1
#    undef HU_CL_MIN_VERSION
#    define HU_CL_MIN_VERSION(x, y) ((x) *100 + (y)) <= _MSC_FULL_VERS
#endif

#if defined(__GNUC__) || defined(__clang__)
#    undef HU_COMP_GNULIKE_P
#    define HU_COMP_GNULIKE_P 1
#endif

#ifdef __GNUC__
#    undef HU_GNUC_MIN_VERSION
#    define HU_GNUC_MIN_VERSION(x, y, z)                                       \
        HU_MIN_VERSION(x, y, z, __GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__)
#else
#    define HU_GNUC_MIN_VERSIOJN(x, y, z) 0
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

#if (HU_COMP_GCC_P + HU_COMP_CLANG_P + HU_COMP_INTEL_P + HU_COMP_MSVC_P) != 1
#    error "BUG: HU_COMP_*_P not properly detected"
#endif

#endif

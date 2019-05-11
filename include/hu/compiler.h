#ifndef HU_COMPILER_H
#define HU_COMPILER_H

#define HU_COMP_CLANG_P 0
#define HU_COMP_COMPCERT_P 0
#define HU_COMP_GCC_P 0
#define HU_COMP_IBMXL_P 0 /* On newer versions implies HU_COMP_CLANG_P */
#define HU_COMP_INTEL_P 0
#define HU_COMP_MSVC_P 0

#define HU_COMP_GNUC_P 0

#define HU_COMP_PREREQ(ax, ay, az, bx, by, bz)                                 \
    ((ax) *10000L + (ay) *100L + (az) <= (bx) *10000L + (by) *100L + (bz))

#define HU_CLANG_PREREQ(x, y, z) 0
#define HU_COMPCERT_PREREQ(x, y) 0
#define HU_GCC_PREREQ(x, y, z) 0
#define HU_GNUC_PREREQ(x, y, z) 0
#define HU_IBMXL_PREREQ(x, y, z) 0
#define HU_INTEL_PREREQ(x, y) 0
#define HU_MSVC_PREREQ(x, y) 0

#ifdef __GNUC__
#    undef HU_COMP_GNUC_P
#    define HU_COMP_GNUC_P 1
#    define HU_COMP_GNUC 1
#    undef HU_GNUC_PREREQ
#    define HU_GNUC_PREREQ(x, y, z)                                            \
        HU_COMP_PREREQ(x, y, z, __GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__)
#endif

#ifdef __clang__
#    undef HU_COMP_CLANG_P
#    define HU_COMP_CLANG_P 1
#    define HU_COMP_CLANG 1
#    undef HU_CLANG_PREREQ
#    define HU_CLANG_PREREQ(x, y, z)                                           \
        HU_COMP_PREREQ(                                                        \
          x, y, z, __clang_major__, __clang_minor__, __clang_patchlevel__)
#elif defined(__ICC) || defined(__INTEL_COMPILER)
#    undef HU_COMP_INTEL_P
#    define HU_COMP_INTEL_P 1
#    define HU_COMP_INTEL 1
#    ifdef __INTEL_COMPILER
#        undef HU_INTEL_PREREQ
#        define HU_INTEL_PREREQ(x, y) ((x) *100L + (y) <= __INTEL_COMPILER)
#    endif
#elif defined(__GNUC__)
#    undef HU_COMP_GCC_P
#    define HU_COMP_GCC_P 1
#    define HU_COMP_GCC 1
#    undef HU_GCC_PREREQ
#    define HU_GCC_PREREQ(x, y, z) HU_GNUC_PREREQ(x, y, z)
#endif

#ifdef __COMPCERT__
#    undef HU_COMP_COMPCERT_P
#    define HU_COMP_COMPCERT_P 1
#    define HU_COMP_COMPCERT 1
#    undef HU_COMPCERT_PREREQ
#    define HU_COMPCERT_PREREQ(x, y) ((x) *100L + (y) <= __COMPCERT_VERSION__)
#endif

#ifdef __ibmxl__
#    undef HU_COMP_IBMXL_P
#    define HU_COMP_IBMXL_P 1
#    define HU_COMP_IBMXL 1
#    undef HU_IBMXL_PREREQ
#    define HU_IBXML_PREREQ(x, y, z)                                           \
        HU_COMP_PREREQ(x,                                                      \
                       y,                                                      \
                       z,                                                      \
                       __ibmxl_version__,                                      \
                       __ibmxl_release__,                                      \
                       __ibmxl_modification__)
#endif

#ifdef _MSC_VER
#    undef HU_COMP_MSVC_P
#    define HU_COMP_MSVC_P 1
#    define HU_COMP_MSVC 1
#    undef HU_MSVC_PREREQ
#    define HU_MSVC_PREREQ(x, y) ((x) *100L + (y) <= _MSC_VERS)
#endif

/* define alias */
#define HU_COMP_GNULIKE_P HU_COMP_GNUC_P
#if HU_COMP_GNUC_P
#    define HU_COMP_GNULIKE 1
#endif

#if ((HU_COMP_CLANG_P || HU_COMP_IBMXL_P) + HU_COMP_COMPCERT_P +               \
     HU_COMP_GCC_P + HU_COMP_INTEL_P + HU_COMP_MSVC_P) != 1
#    error "BUG: HU_COMP_*_P not properly detected"
#endif

#endif

#ifndef HU_PLATFORM_H
#define HU_PLATFORM_H

#define HU_COMP_GCC_P 0
#define HU_COMP_CLANG_P 0
#define HU_COMP_INTEL_P 0
#define HU_COMP_MSVC_P 0

#define HU_BITS_32_P 0
#define HU_BITS_64_P 0

#define HU_OS_POSIX_P 0
#define HU_OS_LINUX_P 0     /* implies POSIX */
#define HU_OS_BSD_P 0       /* implies POSIX */
#define HU_OS_FREEBSD_P 0   /* implies BSD */
#define HU_OS_OPENBSD_P 0   /* implies BSD */
#define HU_OS_DRAGONFLY_P 0 /* implies BSD */
#define HU_OS_NETBSD_P 0    /* implies BSD */
#define HU_OS_MAC_P 0
#define HU_OS_OSX_P 0 /* implies MAC */
#define HU_OS_IOS_P 0 /* implies MAC */
#define HU_OS_WINDOWS_P 0
#define HU_OS_ANDROID_P 0

#define HU_MACH_X86_P 0
#define HU_MACH_ARM_P 0

#define HU_C_P 0
#define HU_C_89_P 0
#define HU_C_99_P 0
#define HU_C_11_P 0
#define HU_C_17_P 0

#define HU_CXX_P 0
#define HU_CXX_98_P 0
#define HU_CXX_11_P 0
#define HU_CXX_14_P 0
#define HU_CXX_17_P 0

#define HU_CXX_EXCEPTIONS_P 0
#define HU_CXX_RTTI_P 0

#define HU_LITTLE_ENDIAN_P 0
#define HU_BIG_ENDIAN_P 0

#ifdef __clang__
#undef HU_COMP_CLANG_P
#define HU_COMP_CLANG_P 1
#elif defined(__ICC) || defined(__INTEL_COMPILER)
#undef HU_COMP_INTEL_P
#define HU_COMP_INTEL_P 1
#elif defined(__GNUC__)
#undef HU_COMP_GCC_P
#define HU_COMP_GCC_P 1
#endif

#ifdef _MSC_VER
#undef HU_COMP_MSVC_P
#define HU_COMP_MSVC_P 1
#endif

#if defined(__x86_64__) || defined(__aarch64__) || defined(_M_AMD64)
#undef HU_BITS_64_P
#define HU_BITS_64_P 1
#endif

#if defined(__i386) || defined(__i386__) ||                                    \
  defined(__arm__) && !defined(__aarch64__)
#undef HU_BITS_32_P
#define HU_BITS_32_P 1
#endif

#if defined(__linux__) || defined(__linux) ||                                  \
  defined(__gnu_linux__) && !defined(__ANDROID__)
#undef HU_OS_LINUX_P
#define HU_OS_LINUX_P 1
#endif

#ifdef _WIN32
#undef HU_LITTLE_ENDIAN_P
#define HU_LITTLE_ENDIAN_P 1
#undef HU_OS_WINDOWS_P
#define HU_OS_WINDOWS_P 1
#ifdef _WIN64
#undef HU_BITS_64_P
#define HU_BITS_64_P 1
#else
#undef HU_BITS_32_P
#define HU_BITS_32_P 1
#endif
#endif

#ifdef __APPLE__
#include <TargetConditionals.h>
#undef HU_OS_MAC_P
#define HU_OS_MAC_P 1
#if TARGET_IPHONE_SIMULATOR || TARGET_OS_IPHONE
#undef HU_OS_IOS_P
#define HU_OS_IOS_P 1
#else
#undef HU_OS_OSX_P
#define HU_OS_OSX_P 1
#endif
#endif

#ifdef __ANDROID__
#undef HU_OS_ANDROID_P
#define HU_OS_ANDROID_P 1
#endif

#ifdef __FreeBSD__
#undef HU_OS_BSD_P
#define HU_OS_BSD_P 1
#undef HU_OS_FREEBSD_P
#define HU_OS_FREEBSD_P 1
#endif

#ifdef __OpenBSD__
#undef HU_OS_BSD_P
#define HU_OS_BSD_P 1
#undef HU_OS_OPENBSD_P
#define HU_OS_OPENBSD_P 1
#endif

#ifdef __DragonFly__
#undef HU_OS_BSD_P
#define HU_OS_BSD_P 1
#undef HU_OS_DRAGONFLY_P
#define HU_OS_DRAGONFLY_P 1
#endif

#ifdef __NetBSD__
#undef HU_OS_BSD_P
#define HU_OS_BSD_P 1
#undef HU_OS_NETBSD_P
#define HU_OS_NETBSD_P 1
#endif

#if defined(_POSIX_VERSION) || defined(__unix__) || defined(__unix) ||         \
  HU_OS_MAC_P
#undef HU_OS_POSIX_P
#define HU_OS_POSIX_P 1
#endif

#ifdef __GNUC__
#undef HU_COMP_GNULIKE_P
#define HU_COMP_GNULIKE_P 1
#endif

#ifdef _MSC_VER
#undef HU_COMP_MSVC_P
#define HU_COMP_MSVC_P 1
#endif

#if defined(__x86_64__) || defined(__amd64__) || defined(__i386) ||            \
  defined(_M_IX86) || defined(_M_AMD64) || defined(_M_X64)
#undef HU_MACH_X86_P
#define HU_MACH_X86_P 1
#endif

#if defined(__arm__) || defined(_M_ARM) || defined(__aarch64__)
#undef HU_MACH_ARM_P
#define HU_MACH_ARM_P 1
#endif

#ifdef __STDC__

#undef HU_C_P
#define HU_C_P 1
#undef HU_C_89_P
#define HU_C_89_P 1

#ifndef __STDC_VERSION__
#define HU_C_VERS 1989
#elif __STDC_VERSION__ == 199901L
#define HU_C_VERS 1999
#elif __STDC_VERSION__ == 201112L
#define HU_C_VERS 2011
#elif __STDC_VERSION__ == 201710L
#define HU_C_VERS 2017
#elif __STDC_VERSION__ > 201710L
#define HU_C_VERS 9999
#endif

#if HU_C_VERS >= 1999
#undef HU_C_99_P
#define HU_C_99_P 1
#endif

#if HU_C_VERS >= 2011
#undef HU_C_11_P
#define HU_C_11_P 1
#endif

#if HU_C_VERS >= 2017
#undef HU_C_17_P
#define HU_C_17_P 1
#endif

#endif /* __STDC__ */

#ifdef __cplusplus

#undef HU_CXX_P
#define HU_CXX_P 1

#undef HU_CXX_98_P
#define HU_CXX_98_P 1

#undef HU_CXX_EXCEPTIONS_P
#define HU_CXX_EXCEPTIONS_P 1

#undef HU_CXX_RTTI_P
#define HU_CXX_RTTI_P 1

#if __cplusplus == 199711L
#define HU_CXX_VERS 1998
#elif __cplusplus == 201103L
#define HU_CXX_VERS 2011
#elif __cplusplus == 201402L
#define HU_CXX_VERS 2014
#elif __cplusplus == 201703L
#define HU_CXX_VERS 2017
#elif __cplusplus > 201703L
#define HU_CXX_VERS 9999
#endif

#if HU_CXX_VERS >= 2011
#undef HU_CXX_11_P
#define HU_CXX_11_P 1
#endif

#if HU_CXX_VERS >= 2014
#undef HU_CXX_14_P
#define HU_CXX_14_P 1
#endif

#if HU_CXX_VERS >= 2017
#undef HU_CXX_17_P
#define HU_CXX_17_P 1
#endif

#endif /* __cplusplus */

#if (defined(__BYTE_ORDER__) && __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__) ||  \
  (defined(__BYTE_ORDER) && __BYTE_ORDER == __LITTLE_ENDIAN)
#undef HU_LITTLE_ENDIAN_P
#define HU_LITTLE_ENDIAN_P 1
#endif

#if (defined(__BYTE_ORDER__) && __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__) ||     \
  (defined(__BYTE_ORDER) && __BYTE_ORDER == __BIG_ENDIAN) ||                   \
  defined(__BIG_ENDIAN__)
#undef HU_BIG_ENDIAN_P
#define HU_BIG_ENDIAN_P 1
#endif

#if HU_COMP_GCC_P || HU_COMP_CLANG_P || HU_COMP_INTEL_P
#undef HU_COMP_GNULIKE_P
#define HU_COMP_GNULIKE_P 1
#elif HU_COMP_MSVC_P
#define HU_COMP_MSVC 1
#else
#error "failed to detect compiler"
#endif

#if HU_CXX_P
#if HU_COMP_MSVC_P && !defined(_CPPUNWIND) ||                                  \
  HU_COMP_GNULIKE_P && !(defined(__cpp_exceptions) || defined(__EXCEPTIONS))
#undef HU_CXX_EXCEPTIONS_P
#define HU_CXX_EXCEPTIONS_P 0
#endif
#if HU_COMP_MSVC_P && !defined(_CPPRTTI) ||                                    \
  HU_COMP_GNULIKE_P && !(defined(__cpp_rtti) || defined(__GXX_RTTI))
#undef HU_CXX_RTTI_P
#define HU_CXX_RTTI_P 0
#endif
#endif

#if HU_COMP_GCC_P
#define HU_COMP_GCC 1
#endif

#if HU_COMP_CLANG_P
#define HU_COMP_CLANG 1
#endif

#if HU_COMP_INTEL_P
#define HU_COMP_INTEL 1
#endif

#if HU_COMP_MSVC_P
#define HU_COMP_MSVC 1
#endif

#if HU_BITS_32_P
#define HU_BITS_32 1
#endif

#if HU_BITS_64_P
#define HU_BITS_64 1
#endif

#if HU_BITS_32_P && HU_BITS_64_P
#error "BUG: HU_BITS_32_P and HU_BITS_64_P are both true"
#endif

#if !HU_BITS_32_P && !HU_BITS_64_P
#error "failed to detect bitness of platform"
#endif

#if HU_OS_POSIX_P
#define HU_OS_POSIX 1
#endif

#if HU_OS_LINUX_P
#define HU_OS_LINUX 1
#endif

#if HU_OS_BSD_P
#define HU_OS_BSD 1
#endif

#if HU_OS_FREEBSD_P
#define HU_FREEOS_BSD 1
#endif

#if HU_OS_OPENBSD_P
#define HU_OS_BSD 1
#endif

#if HU_OS_DRAGONFLY_P
#define HU_OS_DRAGONFLY 1
#endif

#if HU_OS_NETBSD_P
#define HU_OS_NETBSD_P 1
#endif

#if HU_OS_MAC_P
#define HU_OS_MAC 1
#endif

#if HU_OS_OSX_P
#define HU_OS_OSX 1
#endif

#if HU_OS_IOS_P
#define HU_OS_IOS 1
#endif

#if HU_OS_WINDOWS_P
#define HU_OS_WINDOWS 1
#endif

#if HU_OS_ANDROID_P
#define HU_OS_ANDROID 1
#endif

#if HU_OS_LINUX_P + HU_OS_FREEBSD_P + HU_OS_OPENBSD_P + HU_OS_DRAGONFLY_P +    \
    HU_OS_NETBSD_P + HU_OS_OSX_P + HU_OS_IOS_P + HU_OS_WINDOWS_P +             \
    HU_OS_ANDROID_P !=                                                         \
  1
#error "BUG: HU_OS_*_P not properly defined"
#endif

#if HU_C_P
#define HU_C 1
#endif

#if HU_C_89_P
#define HU_C_89 1
#endif

#if HU_C_99_P
#define HU_C_99 1
#endif

#if HU_C_11_P
#define HU_C_11 1
#endif

#if HU_C_17_P
#define HU_C_17 1
#endif

#if HU_CXX_P
#define HU_CXX 1
#endif

#if HU_CXX_11_P
#define HU_CXX_11 1
#endif

#if HU_CXX_14_P
#define HU_CXX_14 1
#endif

#if HU_CXX_17_P
#define HU_CXX_17 1
#endif

#if HU_CXX_EXCEPTIONS_P
#define HU_CXX_EXCEPTIONS 1
#endif

#if HU_CXX_RTTI_P
#define HU_CXX_RTTI 1
#endif

#if HU_LITTLE_ENDIAN_P
#define HU_LITTLE_ENDIAN 1
#endif

#if HU_BIG_ENDIAN_P
#define HU_BIG_ENDIAN 1
#endif

#if HU_LITTLE_ENDIAN_P + HU_BIG_ENDIAN_P != 1
#error "BUG: HU_LITTLE_ENDIAN_P and HU_BIG_ENDIAN_P are both true"
#endif

#if !HU_LITTLE_ENDIAN_P && !HU_BIG_ENDIAN_P
#error "failed to detect endianess of platform"
#endif

#if HU_MACH_X86_P
#define HU_MACH_X86 1
#endif

#if HU_MACH_ARM_P
#define HU_MACH_ARM 1
#endif

#if HU_MACH_X86_P + HU_MACH_ARM_P != 1
#error "BUG: HU_MACH_*_P not properly defined"
#endif

#endif
